#pragma once
#include "../template.hpp"
#include "persistent_array.hpp"

// https://github.com/winter-2521/cp-library

// 永続 Union-Find (Persistent Union-Find)．どの版にも辺を足せて，新しい版の番号を返す (オンライン)
// 親の配列を永続配列で持ち，経路圧縮はせずに union by size だけ行う (木の高さ O(log n))
// par[x] < 0 なら x は根で -par[x] がその連結成分の大きさ
// find O(log n · log_8 n)，unite O(log n · log_8 n)
struct PersistentUnionFind {
    PersistentArray<int, 3> par;

    PersistentUnionFind(int n = 0) : par(n, -1) {}

    void reserve(int q) { par.reserve(2 * q); }

    // 初期状態 (辺なし) の版の番号
    static constexpr int initial_version() { return 0; }

    // 版 v での x の根
    int leader(int v, int x) const {
        while (true) {
            int p = par.get(v, x);
            if (p < 0) return x;
            x = p;
        }
    }

    bool same(int v, int x, int y) const { return leader(v, x) == leader(v, y); }

    // 版 v の x を含む連結成分の大きさ
    int size(int v, int x) const { return -par.get(v, leader(v, x)); }

    // 版 v に辺 (x, y) を足した版を作り，その番号を返す (すでに連結でも新しい版を作る)
    int merge(int v, int x, int y) {
        x = leader(v, x), y = leader(v, y);
        if (x == y) return par.set(v, x, par.get(v, x));
        int sx = -par.get(v, x), sy = -par.get(v, y);
        if (sx < sy) swap(x, y), swap(sx, sy);
        int w = par.set(v, x, -(sx + sy));
        return par.set(w, y, x);
    }
};
