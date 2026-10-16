#pragma once
#include "../template.hpp"
#include "../algebra/acted_monoid.hpp"

// https://github.com/winter-2521/cp-library

// k-d 木 (2 次元の点に対する長方形作用・長方形積・一点更新)
// AM は作用付きモノイド (algebra/acted_monoid.hpp 参照)．積は可換であること (点の順番は決まっていないため)
// 点をバランスよく 2 分割した木で，各ノードは点の外接長方形・積・遅延作用を持つ
// 長方形クエリ O(√n)，一点更新 O(log n)
template <class X, class AM>
struct KDTree {
    using S = typename AM::S;
    using F = typename AM::F;
    struct Node {
        X x0, x1, y0, y1;  // 外接長方形 (閉区間)
        S val;
        F lz;
        bool has_lz;
    };
    int n;
    vector<Node> d;
    vector<int> leaf;       // leaf[i]: 点 i の葉のノード番号
    vector<char> internal;  // 子を持つノードか

    KDTree() : n(0) {}
    KDTree(const vector<X> &xs, const vector<X> &ys, const vector<S> &vals) : n(xs.size()) {
        leaf.resize(n);
        if (n == 0) return;
        d.resize(4 * n), internal.assign(4 * n, 0);
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        build(1, ord.begin(), ord.end(), xs, ys, vals);
    }

    int size() const { return n; }

    // l <= x < r, d <= y < u の点の積
    S prod(X l, X dd, X r, X u) {
        if (n == 0 || !(l < r) || !(dd < u)) return AM::e();
        return prod_rec(1, l, dd, r - 1, u - 1);
    }

    // l <= x < r, d <= y < u の点に f を作用
    void apply(X l, X dd, X r, X u, const F &f) {
        if (n == 0 || !(l < r) || !(dd < u)) return;
        apply_rec(1, l, dd, r - 1, u - 1, f);
    }

    S all_prod() const { return n ? d[1].val : AM::e(); }

    // 点 i (構築時の番号) の値
    S get(int i) {
        push_path(leaf[i]);
        return d[leaf[i]].val;
    }

    // 点 i の値を x にする
    void set(int i, const S &x) {
        int k = leaf[i];
        push_path(k);
        d[k].val = x;
        for (k >>= 1; k; k >>= 1) d[k].val = AM::op(d[2 * k].val, d[2 * k + 1].val);
    }

    // 全ての点の現在の値 (構築時の番号順)．O(n)
    vector<S> values() {
        vector<S> res(n);
        // 親は子より番号が小さいので，番号順に push すれば全ての遅延が葉まで降りる
        for (int k = 1; k < (int)d.size(); k++) if (internal[k]) push(k);
        for (int i = 0; i < n; i++) res[i] = d[leaf[i]].val;
        return res;
    }

  private:
    using It = vector<int>::iterator;
    void build(int k, It b, It e, const vector<X> &xs, const vector<X> &ys, const vector<S> &vals) {
        Node &nd = d[k];
        nd.x0 = nd.x1 = xs[*b], nd.y0 = nd.y1 = ys[*b];
        for (It it = b; it != e; ++it) {
            nd.x0 = std::min(nd.x0, xs[*it]), nd.x1 = std::max(nd.x1, xs[*it]);
            nd.y0 = std::min(nd.y0, ys[*it]), nd.y1 = std::max(nd.y1, ys[*it]);
        }
        nd.lz = AM::id(), nd.has_lz = false;
        if (e - b == 1) {
            nd.val = vals[*b];
            leaf[*b] = k;
            return;
        }
        // 深さごとに x, y を交互に，中央値で分ける
        // (広がりの大きい軸で分けると，y が数種類しかない入力で y の細い帯のクエリが O(n) になる)
        internal[k] = 1;
        It m = b + (e - b) / 2;
        bool by_x = (31 - __builtin_clz(k)) % 2 == 0;
        if (by_x) nth_element(b, m, e, [&](int i, int j) { return xs[i] < xs[j]; });
        else nth_element(b, m, e, [&](int i, int j) { return ys[i] < ys[j]; });
        build(2 * k, b, m, xs, ys, vals);
        build(2 * k + 1, m, e, xs, ys, vals);
        d[k].val = AM::op(d[2 * k].val, d[2 * k + 1].val);
    }

    void all_apply(int k, const F &f) {
        Node &nd = d[k];
        nd.val = AM::mapping(f, nd.val);
        nd.lz = nd.has_lz ? AM::composition(f, nd.lz) : f;
        nd.has_lz = true;
    }
    void push(int k) {
        if (!d[k].has_lz) return;
        all_apply(2 * k, d[k].lz);
        all_apply(2 * k + 1, d[k].lz);
        d[k].has_lz = false;
    }
    void push_path(int k) {
        int h = 31 - __builtin_clz(k);
        for (int s = h; s > 0; s--) push(k >> s);
    }

    // [l, r] × [dd, u] (閉区間)
    S prod_rec(int k, X l, X dd, X r, X u) {
        const Node &nd = d[k];
        if (nd.x1 < l || r < nd.x0 || nd.y1 < dd || u < nd.y0) return AM::e();
        if (l <= nd.x0 && nd.x1 <= r && dd <= nd.y0 && nd.y1 <= u) return nd.val;
        push(k);
        return AM::op(prod_rec(2 * k, l, dd, r, u), prod_rec(2 * k + 1, l, dd, r, u));
    }

    void apply_rec(int k, X l, X dd, X r, X u, const F &f) {
        Node &nd = d[k];
        if (nd.x1 < l || r < nd.x0 || nd.y1 < dd || u < nd.y0) return;
        if (l <= nd.x0 && nd.x1 <= r && dd <= nd.y0 && nd.y1 <= u) return all_apply(k, f);
        push(k);
        apply_rec(2 * k, l, dd, r, u, f);
        apply_rec(2 * k + 1, l, dd, r, u, f);
        d[k].val = AM::op(d[2 * k].val, d[2 * k + 1].val);
    }

};

// 点の追加もできる k-d 木 (オンライン)
// 大きさが 2 冪の KDTree を高々 log 個持ち，追加のたびに同じ大きさのものを併合して作り直す (二進カウンタ)
// 長方形クエリ O(√n)，一点更新 O(log n)，追加ならし O(log^2 n)
template <class X, class AM>
struct DynamicKDTree {
    using S = typename AM::S;
    using F = typename AM::F;
    struct Bucket {
        vector<int> ids;  // 含む点の番号 (KDTree の中の番号順)
        KDTree<X, AM> kd;
    };
    vector<X> px, py;            // 点の座標 (追加順)
    vector<int> where, local;    // 点 i はバケット where[i] の local[i] 番目
    vector<Bucket> buckets;

    DynamicKDTree() = default;
    DynamicKDTree(const vector<X> &xs, const vector<X> &ys, const vector<S> &vals) : px(xs), py(ys) {
        int n = xs.size();
        where.assign(n, 0), local.resize(n);
        if (n == 0) return;
        Bucket b;
        b.ids.resize(n);
        iota(b.ids.begin(), b.ids.end(), 0);
        b.kd = KDTree<X, AM>(xs, ys, vals);
        for (int i = 0; i < n; i++) local[i] = i;
        buckets.push_back(std::move(b));
    }

    int size() const { return px.size(); }

    // 点 (x, y) を値 v で追加し，その番号を返す
    int add_point(X x, X y, const S &v) {
        int id = px.size();
        px.push_back(x), py.push_back(y), where.push_back(0), local.push_back(0);
        vector<int> ids{id};
        vector<S> vals{v};
        while (!buckets.empty() && buckets.back().ids.size() <= ids.size()) {
            Bucket &t = buckets.back();
            vector<S> tv = t.kd.values();
            ids.insert(ids.end(), t.ids.begin(), t.ids.end());
            vals.insert(vals.end(), tv.begin(), tv.end());
            buckets.pop_back();
        }
        int m = ids.size();
        vector<X> xs(m), ys(m);
        for (int k = 0; k < m; k++) xs[k] = px[ids[k]], ys[k] = py[ids[k]];
        Bucket b;
        b.kd = KDTree<X, AM>(xs, ys, vals);
        b.ids = std::move(ids);
        int bi = buckets.size();
        for (int k = 0; k < m; k++) where[b.ids[k]] = bi, local[b.ids[k]] = k;
        buckets.push_back(std::move(b));
        return id;
    }

    S get(int i) { return buckets[where[i]].kd.get(local[i]); }
    void set(int i, const S &v) { buckets[where[i]].kd.set(local[i], v); }

    // l <= x < r, d <= y < u の点の積
    S prod(X l, X d, X r, X u) {
        S res = AM::e();
        for (auto &b : buckets) res = AM::op(res, b.kd.prod(l, d, r, u));
        return res;
    }

    // l <= x < r, d <= y < u の点に f を作用
    void apply(X l, X d, X r, X u, const F &f) {
        for (auto &b : buckets) b.kd.apply(l, d, r, u, f);
    }
};
