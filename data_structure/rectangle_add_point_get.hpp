#pragma once
#include "../template.hpp"
#include "static_rectangle_sum.hpp"

// 長方形加算・一点取得 (Rectangle Add Point Get)．オンライン
// 長方形 [l, r) × [d, u) に w を足すのを，4 隅に ±w の点を置くこと (2 次元の差分) に直す．
// 点 (x, y) の値 = x' <= x かつ y' <= y の点の重みの和 (DynamicRectangleSum で数える)
// 加算ならし O(log^2 n)，取得 O(log^2 n)
template <class X, class W>
struct RectangleAddPointGet {
    DynamicRectangleSum<X, W> rs;

    RectangleAddPointGet() = default;
    // 初期の長方形 (l[i], d[i], r[i], u[i], w[i]) をまとめて入れる
    RectangleAddPointGet(const vector<X> &l, const vector<X> &d, const vector<X> &r, const vector<X> &u, const vector<W> &w) {
        int n = l.size();
        vector<X> xs, ys;
        vector<W> ws;
        xs.reserve(4 * n), ys.reserve(4 * n), ws.reserve(4 * n);
        for (int i = 0; i < n; i++) {
            xs.push_back(l[i]), ys.push_back(d[i]), ws.push_back(w[i]);
            xs.push_back(l[i]), ys.push_back(u[i]), ws.push_back(-w[i]);
            xs.push_back(r[i]), ys.push_back(d[i]), ws.push_back(-w[i]);
            xs.push_back(r[i]), ys.push_back(u[i]), ws.push_back(w[i]);
        }
        rs = DynamicRectangleSum<X, W>(xs, ys, ws);
    }

    // l <= x < r, d <= y < u の全ての点に w を足す
    void add(X l, X d, X r, X u, W w) {
        rs.add(l, d, w), rs.add(l, u, -w), rs.add(r, d, -w), rs.add(r, u, w);
    }

    // 点 (x, y) の値
    W get(X x, X y) const {
        X lo = numeric_limits<X>::lowest();
        return rs.sum_rect(lo, lo, x + 1, y + 1);
    }
};
