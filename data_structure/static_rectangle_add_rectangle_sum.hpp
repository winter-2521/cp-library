#pragma once
#include "../template.hpp"
#include "static_rectangle_sum.hpp"

// https://github.com/winter-2521/cp-library

// 長方形加算をすべて行った後の長方形和 (Static Rectangle Add Rectangle Sum)．加算の後のクエリはオンライン
// 長方形 [l, r) × [d, u) への w の加算を 4 隅の点 (p, q, ±w) にすると，
//   S(X, Y) = Σ_{x<X, y<Y} A[x][y] = Σ_{p<X, q<Y} c (X - p)(Y - q)
//           = XY Σc - X Σcq - Y Σcp + Σcpq
// なので，重み (c, cp, cq, cpq) の長方形和 (StaticRectangleSum) 1 回で S(X, Y) が求まる
// 構築 O(n log n)，クエリ O(log n)．T は値の型 (modint など．座標の積を T で計算する)
template <class X, class T>
struct StaticRectangleAddRectangleSum {
    struct Quad {
        T c, cp, cq, cpq;
        Quad(int z = 0) : c(z), cp(z), cq(z), cpq(z) {}
        Quad(T c, T cp, T cq, T cpq) : c(c), cp(cp), cq(cq), cpq(cpq) {}
        Quad &operator+=(const Quad &o) { return c += o.c, cp += o.cp, cq += o.cq, cpq += o.cpq, *this; }
        Quad operator+(const Quad &o) const { return Quad(*this) += o; }
        Quad operator-(const Quad &o) const { return Quad(c - o.c, cp - o.cp, cq - o.cq, cpq - o.cpq); }
    };
    vector<X> xs, ys;
    vector<Quad> ws;
    StaticRectangleSum<X, Quad> rs;
    bool built = false;

    StaticRectangleAddRectangleSum() = default;

    // l <= x < r, d <= y < u に w を足す (build 前に呼ぶこと)
    void add(X l, X d, X r, X u, T w) {
        assert(!built);
        add_corner(l, d, w), add_corner(l, u, -w), add_corner(r, d, -w), add_corner(r, u, w);
    }

    void build() {
        rs = StaticRectangleSum<X, Quad>(xs, ys, ws);
        built = true;
    }

    // l <= x < r, d <= y < u の和 (初回に build していなければ build する)
    T sum(X l, X d, X r, X u) {
        if (!built) build();
        return prefix(r, u) - prefix(l, u) - prefix(r, d) + prefix(l, d);
    }

    // x < X, y < Y の和
    T prefix(X x, X y) const {
        X lo = numeric_limits<X>::lowest();
        Quad q = rs.sum_rect(lo, lo, x, y);
        T tx(x), ty(y);
        return tx * ty * q.c - tx * q.cq - ty * q.cp + q.cpq;
    }

  private:
    void add_corner(X p, X q, T c) {
        xs.push_back(p), ys.push_back(q);
        T tp(p), tq(q);
        ws.emplace_back(c, c * tp, c * tq, c * tp * tq);
    }
};
