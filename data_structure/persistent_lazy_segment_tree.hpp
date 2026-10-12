#pragma once
#include "../template.hpp"
#include "../algebra/acted_monoid.hpp"

// 永続遅延セグメント木
// 各バージョンを根のノード番号 (int) で表す．更新は新しいバージョンの根を返し，古いバージョンは変わらない
// 1 回の更新で作るノードは O(log n) 個．区間積はノードを作らない
template <class AM>
struct PersistentLazySegmentTree {
    using S = typename AM::S;
    using F = typename AM::F;
    struct Node {
        S val;
        F lz;
        int l, r;
        bool has_lz;  // lz が恒等写像でない可能性があるか
    };
    int n;

    // ノードは 2^16 個ずつのブロックに確保する (vector の再確保によるコピーとメモリの一時的な倍増を避ける)
    static constexpr int BLK = 16;
    vector<unique_ptr<Node[]>> blocks;
    int cnt = 0;

    PersistentLazySegmentTree(int n = 0) : n(n) {}

    // 作ったノードの個数
    int node_count() const { return cnt; }

    // 配列 a (長さ n) のバージョンを作って根を返す
    int build(const vector<S> &a) {
        assert((int)a.size() == n);
        return build(a, 0, n);
    }
    // 全て x のバージョン
    int build(const S &x = AM::e()) { return build(vector<S>(n, x)); }

    // バージョン root の a[p] を x にしたバージョン
    int set(int root, int p, const S &x) {
        int v = clone(root);
        set(v, 0, n, p, x);
        return v;
    }

    S get(int root, int p) const { return prod(root, p, p + 1); }

    // バージョン root の op(a[l], ..., a[r-1])
    S prod(int root, int l, int r) const {
        if (l >= r) return AM::e();
        return prod(root, 0, n, l, r, AM::id());
    }
    S all_prod(int root) const { return nd_(root).val; }

    // バージョン root で i in [l, r) について a[i] = f(a[i]) としたバージョン
    int apply(int root, int l, int r, const F &f) {
        if (l >= r) return root;
        int v = clone(root);
        apply(v, 0, n, l, r, f);
        return v;
    }

    // バージョン dst の [l, r) をバージョン src の [l, r) で置き換えたバージョン
    int copy_range(int dst, int src, int l, int r) {
        if (l >= r) return dst;
        return copy_range(dst, src, 0, n, l, r, AM::id());
    }

    // バージョン root の配列全体
    vector<S> to_vector(int root) const {
        vector<S> res;
        res.reserve(n);
        auto dfs = [&](auto self, int v, int lo, int hi, const F &g) -> void {
            if (hi - lo == 1) {
                res.push_back(AM::mapping(g, nd_(v).val));
                return;
            }
            int mid = (lo + hi) >> 1;
            F h = AM::composition(g, nd_(v).lz);
            self(self, nd_(v).l, lo, mid, h);
            self(self, nd_(v).r, mid, hi, h);
        };
        if (n) dfs(dfs, root, 0, n, AM::id());
        return res;
    }

  private:
    Node &nd_(int i) { return blocks[i >> BLK][i & ((1 << BLK) - 1)]; }
    const Node &nd_(int i) const { return blocks[i >> BLK][i & ((1 << BLK) - 1)]; }
    int new_node(const Node &x) {
        if ((cnt >> BLK) == (int)blocks.size()) blocks.emplace_back(new Node[1 << BLK]);
        nd_(cnt) = x;
        return cnt++;
    }
    int clone(int v) { return new_node(Node(nd_(v))); }
    int build(const vector<S> &a, int lo, int hi) {
        if (hi - lo == 1) {
            return new_node({a[lo], AM::id(), -1, -1, false});
        }
        int mid = (lo + hi) >> 1;
        int l = build(a, lo, mid), r = build(a, mid, hi);
        return new_node({AM::op(nd_(l).val, nd_(r).val), AM::id(), l, r, false});
    }
    void all_apply(int v, const F &f) {
        nd_(v).val = AM::mapping(f, nd_(v).val);
        nd_(v).lz = AM::composition(f, nd_(v).lz);
        nd_(v).has_lz = true;
    }
    // v は今回作ったノード．作用が残っていれば子を両方複製して下ろす (子も今回作ったノードになる)
    // 作用がなければ何もしない (触る子だけを own_left / own_right で複製する)
    void push(int v) {
        if (!nd_(v).has_lz) return;
        int a = clone(nd_(v).l);
        int b = clone(nd_(v).r);
        nd_(v).l = a, nd_(v).r = b;
        const F f = nd_(v).lz;
        all_apply(a, f), all_apply(b, f);
        nd_(v).lz = AM::id();
        nd_(v).has_lz = false;
        fresh_l = fresh_r = true;
    }
    // push の直後に呼ぶ．子が今回作ったノードでなければ複製する
    int own_left(int v) {
        if (!fresh_l) {
            int c = clone(nd_(v).l);
            nd_(v).l = c;
        }
        return nd_(v).l;
    }
    int own_right(int v) {
        if (!fresh_r) {
            int c = clone(nd_(v).r);
            nd_(v).r = c;
        }
        return nd_(v).r;
    }
    bool fresh_l = false, fresh_r = false;
    void begin_push(int v) {
        fresh_l = fresh_r = false;
        push(v);
    }
    void update(int v) { nd_(v).val = AM::op(nd_(nd_(v).l).val, nd_(nd_(v).r).val); }

    void set(int v, int lo, int hi, int p, const S &x) {
        if (hi - lo == 1) {
            nd_(v).val = x;
            return;
        }
        begin_push(v);
        int mid = (lo + hi) >> 1;
        if (p < mid) set(own_left(v), lo, mid, p, x);
        else set(own_right(v), mid, hi, p, x);
        update(v);
    }

    void apply(int v, int lo, int hi, int l, int r, const F &f) {
        if (l <= lo && hi <= r) {
            all_apply(v, f);
            return;
        }
        begin_push(v);
        int mid = (lo + hi) >> 1;
        // own_* は push 直後の状態 (fresh_*) を使うので，再帰の前に両方確定させる
        int a = l < mid ? own_left(v) : -1;
        int b = mid < r ? own_right(v) : -1;
        if (a != -1) apply(a, lo, mid, l, r, f);
        if (b != -1) apply(b, mid, hi, l, r, f);
        update(v);
    }

    // g: まだ下ろしていない上からの作用
    S prod(int v, int lo, int hi, int l, int r, const F &g) const {
        if (l <= lo && hi <= r) return AM::mapping(g, nd_(v).val);
        int mid = (lo + hi) >> 1;
        F h = AM::composition(g, nd_(v).lz);
        if (r <= mid) return prod(nd_(v).l, lo, mid, l, r, h);
        if (mid <= l) return prod(nd_(v).r, mid, hi, l, r, h);
        return AM::op(prod(nd_(v).l, lo, mid, l, r, h), prod(nd_(v).r, mid, hi, l, r, h));
    }

    // g: src 側でまだ下ろしていない上からの作用
    int copy_range(int d, int s, int lo, int hi, int l, int r, const F &g) {
        if (r <= lo || hi <= l) return d;
        if (l <= lo && hi <= r) {
            int v = clone(s);
            all_apply(v, g);
            return v;
        }
        int v = clone(d);
        begin_push(v);
        int mid = (lo + hi) >> 1;
        F h = AM::composition(g, nd_(s).lz);
        int a = copy_range(nd_(v).l, nd_(s).l, lo, mid, l, r, h);
        int b = copy_range(nd_(v).r, nd_(s).r, mid, hi, l, r, h);
        nd_(v).l = a, nd_(v).r = b;
        update(v);
        return v;
    }
};
