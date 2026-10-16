#pragma once
#include "../template.hpp"
#include "../algebra/acted_monoid.hpp"

// https://github.com/winter-2521/cp-library

// 列の挿入・削除・区間反転・区間作用・区間積 (Splay 木)
// AM は作用付きモノイド (algebra/acted_monoid.hpp 参照)
// COMMUTATIVE = false なら非可換なモノイドでも反転できる (逆順の積も持つ．少し遅い)
// 両端に番兵を置き，区間 [l, r) は「l-1 番目を根に，r 番目を根の右の子に splay した後の，その左の子」として取り出す
template <class AM, bool COMMUTATIVE = true>
struct DynamicSequence {
    using S = typename AM::S;
    using F = typename AM::F;
    // 逆順の積 rsum は COMMUTATIVE = false のときだけ持つ
    struct NoRSum {};
    struct WithRSum {
        S rsum;
    };
    struct Node : conditional_t<COMMUTATIVE, NoRSum, WithRSum> {
        int ch[2], p, sz;
        S val, sum;
        F lz;
        bool has_lz, rev;
    };
    vector<Node> d;  // d[0] は空ノード
    int root;

    DynamicSequence(const vector<S> &a = {}) {
        int n = a.size();
        d.reserve(n + 3);
        d.push_back(make_node(AM::e()));
        d[0].sz = 0;
        vector<int> ids(n + 2);
        ids[0] = new_node(AM::e());
        for (int i = 0; i < n; i++) ids[i + 1] = new_node(a[i]);
        ids[n + 1] = new_node(AM::e());
        root = build(ids, 0, n + 2, 0);
    }

    void reserve(int n) { d.reserve(n + 3); }
    int size() const { return d[root].sz - 2; }

    // i 番目の直前に x を挿入 (i = size() なら末尾)
    void insert(int i, const S &x) {
        int t = new_node(x);
        int r = range(i, i);
        d[r].ch[0] = t, d[t].p = r;
        update(r), update(root);
    }
    void push_back(const S &x) { insert(size(), x); }
    void push_front(const S &x) { insert(0, x); }

    // i 番目を削除
    void erase(int i) {
        int r = range(i, i + 1);
        d[r].ch[0] = 0;
        update(r), update(root);
    }

    S get(int i) {
        int t = kth(i + 1);
        splay(t, 0);
        return d[t].val;
    }

    void set(int i, const S &x) {
        int t = kth(i + 1);
        splay(t, 0);
        d[t].val = x;
        update(t);
    }

    // op(a[l], ..., a[r-1])．l == r なら e()
    S prod(int l, int r) {
        if (l == r) return AM::e();
        return d[d[range(l, r)].ch[0]].sum;
    }
    S all_prod() { return prod(0, size()); }

    // i in [l, r) について a[i] = f(a[i])
    void apply(int l, int r, const F &f) {
        if (l == r) return;
        int rr = range(l, r);
        all_apply(d[rr].ch[0], f);
        update(rr), update(root);
    }

    // a[l], ..., a[r-1] を反転
    void reverse(int l, int r) {
        if (r - l <= 1) return;
        int rr = range(l, r);
        toggle(d[rr].ch[0]);
        update(rr), update(root);
    }

    // 列全体 (デバッグ用)．O(n)
    vector<S> to_vector() {
        vector<S> res;
        res.reserve(size());
        dfs(root, res);
        return vector<S>(res.begin() + 1, res.end() - 1);
    }

  private:
    Node make_node(const S &x) {
        Node t;
        t.ch[0] = t.ch[1] = t.p = 0, t.sz = 1;
        t.val = t.sum = x;
        if constexpr (!COMMUTATIVE) t.rsum = x;
        t.lz = AM::id(), t.has_lz = t.rev = false;
        return t;
    }
    int new_node(const S &x) {
        d.push_back(make_node(x));
        return d.size() - 1;
    }

    int build(const vector<int> &ids, int l, int r, int p) {
        if (l == r) return 0;
        int m = (l + r) >> 1, t = ids[m];
        d[t].p = p;
        d[t].ch[0] = build(ids, l, m, t);
        d[t].ch[1] = build(ids, m + 1, r, t);
        update(t);
        return t;
    }

    void update(int t) {
        Node &x = d[t];
        const Node &a = d[x.ch[0]], &b = d[x.ch[1]];
        x.sz = a.sz + b.sz + 1;
        x.sum = AM::op(AM::op(a.sum, x.val), b.sum);
        if constexpr (!COMMUTATIVE) x.rsum = AM::op(AM::op(b.rsum, x.val), a.rsum);
    }

    void all_apply(int t, const F &f) {
        Node &x = d[t];
        x.val = AM::mapping(f, x.val);
        x.sum = AM::mapping(f, x.sum);
        if constexpr (!COMMUTATIVE) x.rsum = AM::mapping(f, x.rsum);
        x.lz = x.has_lz ? AM::composition(f, x.lz) : f;
        x.has_lz = true;
    }

    void toggle(int t) {
        Node &x = d[t];
        swap(x.ch[0], x.ch[1]);
        if constexpr (!COMMUTATIVE) swap(x.sum, x.rsum);
        x.rev ^= 1;
    }

    void push(int t) {
        Node &x = d[t];
        if (x.rev) {
            if (x.ch[0]) toggle(x.ch[0]);
            if (x.ch[1]) toggle(x.ch[1]);
            x.rev = false;
        }
        if (x.has_lz) {
            if (x.ch[0]) all_apply(x.ch[0], x.lz);
            if (x.ch[1]) all_apply(x.ch[1], x.lz);
            x.has_lz = false;
        }
    }

    // x を親の位置に回転 (親の update だけする)
    void rotate(int x) {
        int y = d[x].p, z = d[y].p;
        int c = d[y].ch[1] == x;
        int b = d[x].ch[c ^ 1];
        d[y].ch[c] = b;
        if (b) d[b].p = y;
        d[x].ch[c ^ 1] = y, d[y].p = x;
        d[x].p = z;
        if (z) d[z].ch[d[z].ch[1] == y] = x;
        update(y);
    }

    // x を goal の子になるまで splay (goal = 0 なら根)．x の祖先は push 済みであること
    void splay(int x, int goal) {
        while (d[x].p != goal) {
            int y = d[x].p, z = d[y].p;
            if (z != goal) rotate((d[y].ch[1] == x) == (d[z].ch[1] == y) ? y : x);
            rotate(x);
        }
        update(x);
        if (!goal) root = x;
    }

    // 番兵込みで k 番目のノード (経路を push する)
    int kth(int k) {
        int t = root;
        while (true) {
            push(t);
            int ls = d[d[t].ch[0]].sz;
            if (k < ls) t = d[t].ch[0];
            else if (k == ls) return t;
            else k -= ls + 1, t = d[t].ch[1];
        }
    }

    // [l, r) が「根の右の子の左の子」の部分木になるようにして，根の右の子を返す
    int range(int l, int r) {
        int a = kth(l);
        splay(a, 0);
        int b = kth(r + 1);
        splay(b, a);
        return b;
    }

    void dfs(int t, vector<S> &res) {
        if (!t) return;
        push(t);
        dfs(d[t].ch[0], res);
        res.push_back(d[t].val);
        dfs(d[t].ch[1], res);
    }
};
