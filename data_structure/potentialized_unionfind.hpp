#pragma once
#include "../template.hpp"

// ポテンシャル付き Union-Find
// 各要素 x に群 G の元 a_x を持たせ，「a_x^{-1} a_y = w」という関係を追加・矛盾判定・取得する
// G は非可換群でもよい．加法群なら「a_y - a_x = w」という意味になる
//
// G には次を定義する:
//   using T = 群の元の型;
//   static T op(const T &a, const T &b);  // 群演算 a * b
//   static T inv(const T &a);             // 逆元
//   static T e();                         // 単位元
// T は == で比較できること
template <class G>
struct PotentializedUnionFind {
    using T = typename G::T;
    // 根なら -(集合のサイズ)，そうでなければ親
    vector<int> par;
    // pot[x] = a_{par[x]}^{-1} a_x  (根なら単位元)
    vector<T> pot;

    PotentializedUnionFind(int n = 0) : par(n, -1), pot(n, G::e()) {}

    // 根を返す．経路圧縮のついでに pot[x] を根からの値に更新する
    int leader(int x) {
        if (par[x] < 0) return x;
        int p = par[x];
        int r = leader(p);
        // pot[p] は a_r^{-1} a_p になっている
        if (p != r) pot[x] = G::op(pot[p], pot[x]);
        return par[x] = r;
    }

    bool same(int x, int y) { return leader(x) == leader(y); }

    int size(int x) { return -par[leader(x)]; }

    // a_r^{-1} a_x  (r は x の属する集合の根)
    T potential(int x) {
        leader(x);
        return pot[x];
    }

    // a_x^{-1} a_y．同じ集合に属していること
    T diff(int x, int y) {
        assert(same(x, y));
        return G::op(G::inv(potential(x)), potential(y));
    }

    // a_x^{-1} a_y = w という関係を追加する
    // これまでの関係と矛盾するなら何もせず false，矛盾しなければ true (既に分かっていた関係でも true)
    bool merge(int x, int y, T w) {
        int rx = leader(x), ry = leader(y);
        const T &px = pot[x], &py = pot[y];
        if (rx == ry) return G::op(G::inv(px), py) == w;
        // a_x = a_rx px, a_y = a_ry py, a_y = a_x w より a_rx^{-1} a_ry = px w py^{-1}
        T d = G::op(G::op(px, w), G::inv(py));
        if (par[rx] > par[ry]) {
            // rx の方が小さいので ry の下につける
            par[ry] += par[rx];
            par[rx] = ry;
            pot[rx] = G::inv(d);
        } else {
            par[rx] += par[ry];
            par[ry] = rx;
            pot[ry] = d;
        }
        return true;
    }

    // 集合ごとに要素を列挙
    vector<vector<int>> groups() {
        int n = par.size();
        vector<vector<int>> res(n);
        for (int i = 0; i < n; i++) res[leader(i)].push_back(i);
        res.erase(remove_if(res.begin(), res.end(), [](const vector<int> &v) { return v.empty(); }), res.end());
        return res;
    }
};

// 加法群 (a_y - a_x = w)
template <class X>
struct AdditiveGroup {
    using T = X;
    static T op(const T &a, const T &b) { return a + b; }
    static T inv(const T &a) { return -a; }
    static T e() { return T(0); }
};

// xor の群 (a_x xor a_y = w)．偶奇の制約などに使う
template <class X>
struct XorGroup {
    using T = X;
    static T op(const T &a, const T &b) { return a ^ b; }
    static T inv(const T &a) { return a; }
    static T e() { return T(0); }
};
