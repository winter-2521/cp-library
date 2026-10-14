#pragma once
#include "../template.hpp"

// Li Chao Tree (直線・線分の追加，ある x での最小値)
// 2 種類ある:
//   DynamicLiChaoTree<T>(xlo, xhi) : x ∈ [xlo, xhi) の整数．ノードを必要な分だけ作る (オンライン)
//   LiChaoTree<T>(xs)             : x が xs のどれか (先読みできるとき．配列で持つので速い)
// MAX = true なら最大値．T は値の型 (a x + b が T に収まること)

// 直線 y = a x + b
template <class T>
struct LiChaoLine {
    T a, b;
    T operator()(T x) const { return a * x + b; }
};

template <class T, bool MAX = false>
struct DynamicLiChaoTree {
    using Line = LiChaoLine<T>;
    struct Node {
        Line f;
        int ch[2];
    };
    static constexpr T INF = MAX ? numeric_limits<T>::lowest() : numeric_limits<T>::max();
    T xlo, xhi;
    vector<Node> d;  // d[0] は番兵 (直線なし)
    int root = 0;

    DynamicLiChaoTree(T xlo, T xhi) : xlo(xlo), xhi(xhi) { d.push_back({{0, INF}, {0, 0}}); }

    void reserve(int n) { d.reserve(n); }

    // 直線 y = a x + b を追加
    void add_line(T a, T b) { root = insert(root, xlo, xhi, {a, b}); }

    // 線分 y = a x + b (x ∈ [l, r)) を追加
    void add_segment(T l, T r, T a, T b) {
        l = std::max(l, xlo), r = std::min(r, xhi);
        if (l < r) root = insert_seg(root, xlo, xhi, l, r, {a, b});
    }

    // x での最小値 (最大値)．何もなければ INF (MAX なら lowest)
    T get(T x) const {
        int v = root;
        T lo = xlo, hi = xhi;
        T res = INF;
        while (v) {
            T y = d[v].f(x);
            if (better(y, res)) res = y;
            T m = mid(lo, hi);
            if (x < m) v = d[v].ch[0], hi = m;
            else v = d[v].ch[1], lo = m;
        }
        return res;
    }

  private:
    static bool better(T a, T b) { return MAX ? a > b : a < b; }
    static T mid(T lo, T hi) { return lo + (hi - lo) / 2; }

    int new_node(const Line &f) {
        d.push_back({f, {0, 0}});
        return d.size() - 1;
    }

    // [lo, hi) を担当するノード v に直線 f を入れる
    int insert(int v, T lo, T hi, Line f) {
        if (!v) return new_node(f);
        int res = v;
        while (true) {
            Line &g = d[v].f;
            T m = mid(lo, hi);
            bool bl = better(f(lo), g(lo)), bm = better(f(m), g(m));
            if (bm) swap(f, g);
            if (hi - lo == 1) break;
            // 中央で負けた方 f が勝ちうるのは片側だけ
            int c;
            if (bl != bm) c = 0, hi = m;
            else if (better(f(hi - 1), g(hi - 1))) c = 1, lo = m;
            else break;
            if (!d[v].ch[c]) {
                int u = new_node(f);
                d[v].ch[c] = u;
                break;
            }
            v = d[v].ch[c];
        }
        return res;
    }

    int insert_seg(int v, T lo, T hi, T l, T r, const Line &f) {
        if (r <= lo || hi <= l) return v;
        if (l <= lo && hi <= r) return insert(v, lo, hi, f);
        if (!v) v = new_node({0, INF});
        T m = mid(lo, hi);
        int c0 = insert_seg(d[v].ch[0], lo, m, l, r, f);
        d[v].ch[0] = c0;
        int c1 = insert_seg(d[v].ch[1], m, hi, l, r, f);
        d[v].ch[1] = c1;
        return v;
    }
};

template <class T, bool MAX = false>
struct LiChaoTree {
    using Line = LiChaoLine<T>;
    static constexpr T INF = MAX ? numeric_limits<T>::lowest() : numeric_limits<T>::max();
    int n, sz;
    vector<T> xs;     // 座標 (昇順・重複なし)．葉 i が xs[i] を担当 (i >= n は xs.back() を詰める)
    vector<Line> d;   // d[v]: ノード v の直線 (なければ {0, INF})

    LiChaoTree(vector<T> xs_) : xs(xs_) {
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        n = xs.size();
        sz = 1;
        while (sz < std::max(n, 1)) sz <<= 1;
        if (n == 0) xs.push_back(0);
        xs.resize(sz, xs.back());
        d.assign(2 * sz, {0, INF});
    }

    // 直線 y = a x + b を追加
    void add_line(T a, T b) { insert(1, 0, sz, {a, b}); }

    // 線分 y = a x + b (x ∈ [l, r)) を追加
    void add_segment(T l, T r, T a, T b) {
        int li = lower_bound(xs.begin(), xs.begin() + n, l) - xs.begin();
        int ri = lower_bound(xs.begin(), xs.begin() + n, r) - xs.begin();
        Line f{a, b};
        for (int lv = li + sz, rv = ri + sz, w = 1; lv < rv; lv >>= 1, rv >>= 1, w <<= 1) {
            if (lv & 1) insert(lv, (lv - (sz / w)) * w, (lv - (sz / w)) * w + w, f), lv++;
            if (rv & 1) --rv, insert(rv, (rv - (sz / w)) * w, (rv - (sz / w)) * w + w, f);
        }
    }

    // x での最小値 (最大値)．x は xs に含まれること．何もなければ INF
    T get(T x) const { return get_index(lower_bound(xs.begin(), xs.begin() + n, x) - xs.begin()); }

    // xs[i] での最小値
    T get_index(int i) const {
        T x = xs[i], res = INF;
        for (int v = i + sz; v; v >>= 1) {
            T y = d[v](x);
            if (better(y, res)) res = y;
        }
        return res;
    }

  private:
    static bool better(T a, T b) { return MAX ? a > b : a < b; }

    // ノード v (葉の添字 [lo, hi)) に直線を入れる
    void insert(int v, int lo, int hi, Line f) {
        while (true) {
            Line &g = d[v];
            int m = (lo + hi) >> 1;
            bool bl = better(f(xs[lo]), g(xs[lo])), bm = better(f(xs[m]), g(xs[m]));
            if (bm) swap(f, g);
            if (hi - lo == 1) return;
            if (bl != bm) v = 2 * v, hi = m;
            else if (better(f(xs[hi - 1]), g(xs[hi - 1]))) v = 2 * v + 1, lo = m;
            else return;
        }
    }
};
