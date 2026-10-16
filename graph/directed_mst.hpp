#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// 最小有向全域木 (根 r から全頂点に到達できる，辺の重みの和が最小の有向木)．Chu-Liu/Edmonds 法を
// 併合できるヒープ (skew heap，遅延加算) と Union-Find で O(m log n) にしたもの (Tarjan / Gabow ら)
// 返り値: {重みの和, par (par[v] = v の親．par[r] = r)}．到達できない頂点があれば {-1 相当, 空}
template <class T>
pair<T, vector<int>> directed_mst(int n, const vector<tuple<int, int, T>> &edges, int r) {
    int m = edges.size();
    // skew heap: 各頂点に入ってくる辺 (キーは重み) を入れる．lz は部分木全体に足す値
    vector<int> hl(m, -1), hr(m, -1);
    vector<T> key(m), lz(m, 0);
    for (int i = 0; i < m; i++) key[i] = get<2>(edges[i]);
    auto push = [&](int x) {
        if (lz[x] != 0) {
            if (hl[x] >= 0) key[hl[x]] += lz[x], lz[hl[x]] += lz[x];
            if (hr[x] >= 0) key[hr[x]] += lz[x], lz[hr[x]] += lz[x];
            lz[x] = 0;
        }
    };
    auto meld = [&](auto self, int a, int b) -> int {
        if (a < 0) return b;
        if (b < 0) return a;
        if (key[b] < key[a]) swap(a, b);
        push(a);
        hr[a] = self(self, hr[a], b);
        swap(hl[a], hr[a]);
        return a;
    };
    auto pop = [&](int a) {
        push(a);
        return meld(meld, hl[a], hr[a]);
    };
    vector<int> heap(n, -1);
    for (int i = 0; i < m; i++) {
        int b = get<1>(edges[i]);
        if (b == r) continue;
        hl[i] = hr[i] = -1;
        heap[b] = meld(meld, heap[b], i);
    }
    // 縮約を Union-Find で表す (頂点 → 縮約後の代表)
    vector<int> uf(2 * n, -1);
    auto find = [&](int x) {
        while (uf[x] >= 0) {
            if (uf[uf[x]] >= 0) uf[x] = uf[uf[x]];
            x = uf[x];
        }
        return x;
    };
    // 縮約のたびに新しい頂点 (番号 n, n+1, ...) を作る．par_c[x]: 縮約頂点 x を含む，より大きい縮約頂点
    vector<int> seen(2 * n, -1), in_edge(2 * n, -1), par_c(2 * n, -1), heap2(2 * n, -1);
    for (int v = 0; v < n; v++) heap2[v] = heap[v];
    int cnt = n;
    T total = 0;
    seen[r] = r;
    vector<int> path;
    for (int s = 0; s < n; s++) {
        int v = find(s);
        path.clear();
        while (seen[v] < 0) {
            seen[v] = s;
            path.push_back(v);
            // v に入ってくる最小の辺 (縮約の内側の辺は捨てる)
            while (true) {
                if (heap2[v] < 0) return {T(-1), {}};  // 到達できない
                int e = heap2[v];
                if (find(get<0>(edges[e])) == v) {
                    heap2[v] = pop(e);
                    continue;
                }
                break;
            }
            int e = heap2[v];
            in_edge[v] = e;
            total += key[e];
            // v に入る他の辺は，この辺を使った前提で重みを差し引いておく (縮約したとき用)
            T w = key[e];
            heap2[v] = pop(e);
            if (heap2[v] >= 0) key[heap2[v]] -= w, lz[heap2[v]] -= w;
            int u = find(get<0>(edges[e]));
            if (seen[u] == s) {
                // 閉路: path の u から v までを新しい頂点 c に縮約する
                int c = cnt++;
                int h = -1;
                while (true) {
                    int x = path.back();
                    path.pop_back();
                    uf[x] = c, par_c[x] = c;
                    if (heap2[x] >= 0) h = meld(meld, h, heap2[x]);
                    if (x == u) break;
                }
                heap2[c] = h;
                v = c;  // seen[c] = -1 なので，ループの先頭で c に入る辺を探す
                continue;
            }
            v = u;
        }
    }
    // 復元: 縮約頂点を新しい順に見る．x に入る辺 e を使うなら，e の行き先の元の頂点 b から x までの間の頂点に入る辺は使わない
    // (縮約した閉路のうち，b のところだけ閉路の辺の代わりに e が入る)
    vector<int> par(n, -1);
    vector<char> unused(cnt, 0);
    par[r] = r;
    for (int x = cnt - 1; x >= 0; x--) {
        if (x == r || unused[x]) continue;
        int e = in_edge[x], b = get<1>(edges[e]);
        par[b] = get<0>(edges[e]);
        for (int y = b; y != x; y = par_c[y]) unused[y] = 1;
    }
    return {total, par};
}
