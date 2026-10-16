#pragma once
#include "../template.hpp"
#include "../algebra/monoid.hpp"
#include "fast_set.hpp"
#include "segment_tree.hpp"

// https://github.com/winter-2521/cp-library

// 区間ソートができるセグメント木
// 各位置 i に (キー k_i, 値 a_i) を持ち，一点更新・区間積・区間をキーの昇順 / 降順にソートを処理する
// M はモノイド (非可換でもよい)．キーは [0, 2^LOG) の整数で，全て相異なること
//
// ソート済みの連続部分 (ラン) ごとに，キーの 2 分トライ (要素数・昇順の積・降順の積を持つ) で管理する．
// ソートはトライのマージ，ランの途中で切るのはトライの要素数での分割．
// ランの先頭位置に「そのランの積」を置いたセグメント木で区間積を計算する．
// 計算量: 全体でならし O((n + q) LOG) 回のトライ操作 + 各操作 O(log n)
template <class M, int LOG = 30>
struct SortableSegmentTree {
    using S = typename M::S;
    struct TNode {
        int ch[2];
        int cnt;
        S fwd, bwd;  // キーの昇順 / 降順に並べたときの積
    };
    int n;
    vector<TNode> tr;
    vector<int> free_nodes;
    FastSet starts;       // ランの先頭位置
    vector<int> root;     // root[s]: s から始まるランのトライ
    vector<char> desc;    // desc[s]: ランが降順か
    SegmentTree<M> seg;   // seg[s] = ランの積 (ランの先頭以外は e())

    // keys[i] と vals[i] で初期化 (各要素が長さ 1 のラン)
    SortableSegmentTree(const vector<long long> &keys, const vector<S> &vals)
        : n(keys.size()), starts(n, [](int) { return true; }), root(n), desc(n, 0), seg(vals) {
        assert(keys.size() == vals.size());
        tr.reserve((size_t)n * (LOG + 1) + 1);
        tr.push_back({{0, 0}, 0, M::e(), M::e()});  // 0 番は空
        for (int i = 0; i < n; i++) root[i] = make_single(keys[i], vals[i]);
    }

    int size() const { return n; }

    // 位置 i を (key, x) にする
    void set(int i, long long key, const S &x) {
        split(i), split(i + 1);
        free_trie(root[i]);
        root[i] = make_single(key, x);
        desc[i] = 0;
        seg.set(i, x);
    }

    // 位置 i の (キー, 値)
    pair<long long, S> get(int i) const {
        int s = starts.prev(i);
        int v = root[s], k = i - s;
        if (desc[s]) k = tr[v].cnt - 1 - k;
        long long key = 0;
        for (int d = LOG; d > 0; d--) {
            int c0 = tr[v].ch[0];
            if (k < tr[c0].cnt) {
                v = c0;
            } else {
                k -= tr[c0].cnt;
                v = tr[v].ch[1];
                key |= 1LL << (d - 1);
            }
        }
        return {key, tr[v].fwd};
    }

    // op(a[l], ..., a[r-1])．l == r なら e()
    S prod(int l, int r) {
        if (l >= r) return M::e();
        split(l), split(r);
        return seg.prod(l, r);
    }
    S all_prod() const { return seg.all_prod(); }

    // [l, r) をキーの昇順にソートする
    void sort_asc(int l, int r) { sort_range(l, r, false); }
    // [l, r) をキーの降順にソートする
    void sort_desc(int l, int r) { sort_range(l, r, true); }

  private:
    int new_node() {
        if (!free_nodes.empty()) {
            int v = free_nodes.back();
            free_nodes.pop_back();
            return v;
        }
        tr.push_back({});
        return int(tr.size()) - 1;
    }
    void free_trie(int v) {
        if (!v) return;
        free_trie(tr[v].ch[0]), free_trie(tr[v].ch[1]);
        free_nodes.push_back(v);
    }
    void pull(int v) {
        int a = tr[v].ch[0], b = tr[v].ch[1];
        // 上の方の段は子が片方だけのことが多いので，op を省く
        if (!a || !b) {
            const TNode &c = tr[a | b];
            tr[v].cnt = c.cnt, tr[v].fwd = c.fwd, tr[v].bwd = c.bwd;
            return;
        }
        tr[v].cnt = tr[a].cnt + tr[b].cnt;
        tr[v].fwd = M::op(tr[a].fwd, tr[b].fwd);
        tr[v].bwd = M::op(tr[b].bwd, tr[a].bwd);
    }
    int make_single(long long key, const S &x) {
        assert(0 <= key && key < (1LL << LOG));
        int v = new_node();
        tr[v] = {{0, 0}, 1, x, x};
        for (int d = 1; d <= LOG; d++) {
            int p = new_node();
            int b = key >> (d - 1) & 1;
            tr[p] = {{0, 0}, 1, x, x};
            tr[p].ch[b] = v;
            v = p;
        }
        return v;
    }
    // 2 つのトライをマージ (キーは相異なること)
    int merge(int a, int b) {
        if (!a || !b) return a | b;
        int x0 = merge(tr[a].ch[0], tr[b].ch[0]);
        int x1 = merge(tr[a].ch[1], tr[b].ch[1]);
        tr[a].ch[0] = x0, tr[a].ch[1] = x1;
        free_nodes.push_back(b);
        pull(a);
        return a;
    }
    // キーの小さい方から k 個と残りに分ける (0 < k < cnt(v))
    pair<int, int> split_trie(int v, int k) {
        if (k == 0) return {0, v};
        if (k >= tr[v].cnt) return {v, 0};
        int w = new_node();
        tr[w] = {{0, 0}, 0, M::e(), M::e()};
        int c0 = tr[v].ch[0];
        if (k <= tr[c0].cnt) {
            auto [x, y] = split_trie(c0, k);
            tr[w].ch[0] = y, tr[w].ch[1] = tr[v].ch[1];
            tr[v].ch[0] = x, tr[v].ch[1] = 0;
        } else {
            auto [x, y] = split_trie(tr[v].ch[1], k - tr[c0].cnt);
            tr[w].ch[1] = y;
            tr[v].ch[1] = x;
        }
        pull(v), pull(w);
        return {v, w};
    }
    S run_prod(int s) const { return desc[s] ? tr[root[s]].bwd : tr[root[s]].fwd; }
    // p をランの先頭にする
    void split(int p) {
        if (p <= 0 || p >= n || starts.contains(p)) return;
        int s = starts.prev(p);
        int k = p - s, len = tr[root[s]].cnt;
        if (!desc[s]) {
            auto [a, b] = split_trie(root[s], k);
            root[s] = a, root[p] = b;
        } else {
            // 降順なので，先頭 k 個はキーの大きい方
            auto [a, b] = split_trie(root[s], len - k);
            root[s] = b, root[p] = a;
        }
        desc[p] = desc[s];
        starts.insert(p);
        seg.set(s, run_prod(s));
        seg.set(p, run_prod(p));
    }
    void sort_range(int l, int r, bool d) {
        if (l >= r) return;
        split(l), split(r);
        for (int s = starts.next(l + 1); s != -1 && s < r; s = starts.next(s + 1)) {
            root[l] = merge(root[l], root[s]);
            root[s] = 0;
            starts.erase(s);
            seg.set(s, M::e());
        }
        desc[l] = d;
        seg.set(l, run_prod(l));
    }
};
