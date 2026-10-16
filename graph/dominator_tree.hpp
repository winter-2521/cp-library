#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// 支配木 (Dominator Tree)．根 s から v へのどの道も必ず通る頂点を「v の支配点」と呼び，
// v に最も近い支配点 idom(v) を親とする木を求める．Semi-NCA 法 (Lengauer-Tarjan の半支配点 + 木の上の祖先たどり)
// 1. s から DFS して先行順の番号を振る
// 2. 先行順の逆順に，半支配点 sdom(w) = min{ v : v から w へ，途中が全て w より大きい番号の頂点だけを通る道がある } を
//    「処理済みの頂点を DFS 木の親につなぐ Union-Find (経路圧縮つき，最小の sdom を覚える)」で求める
// 3. idom(w) は DFS 木の親から始めて，番号が sdom(w) 以下になるまで idom をたどったもの
// O(m log n) (3. は最悪 O(n^2) だが実用上ほぼ線形)
// 返り値: par[v] = idom(v)．par[s] = s，s から到達できない頂点は -1
inline vector<int> dominator_tree(int n, const vector<pair<int, int>> &edges, int s) {
    int m = edges.size();
    vector<int> fs(n + 1, 0), rs(n + 1, 0), fadj(m), radj(m);
    for (auto &[a, b] : edges) fs[a + 1]++, rs[b + 1]++;
    for (int i = 0; i < n; i++) fs[i + 1] += fs[i], rs[i + 1] += rs[i];
    {
        vector<int> fp(fs.begin(), fs.end() - 1), rp(rs.begin(), rs.end() - 1);
        for (auto &[a, b] : edges) fadj[fp[a]++] = b, radj[rp[b]++] = a;
    }
    // 先行順 (非再帰 DFS)
    vector<int> num(n, -1), ord, dpar;  // dpar: DFS 木の親 (番号)
    ord.reserve(n), dpar.reserve(n);
    {
        vector<int> it(fs.begin(), fs.end() - 1), stk;
        num[s] = 0, ord.push_back(s), dpar.push_back(-1), stk.push_back(s);
        while (!stk.empty()) {
            int v = stk.back();
            if (it[v] == fs[v + 1]) {
                stk.pop_back();
                continue;
            }
            int w = fadj[it[v]++];
            if (num[w] < 0) {
                num[w] = ord.size(), ord.push_back(w), dpar.push_back(num[v]);
                stk.push_back(w);
            }
        }
    }
    int k = ord.size();
    // 以下は全て先行順の番号で扱う
    vector<int> semi(k), label(k), anc(k, -1), idom(k), stk;
    iota(semi.begin(), semi.end(), 0), iota(label.begin(), label.end(), 0);
    // v から，処理済み (= 番号が大きい) 祖先をたどった中で semi が最小の頂点
    auto eval = [&](int v) {
        if (anc[v] < 0) return v;
        int x = v;
        while (anc[anc[x]] >= 0) stk.push_back(x), x = anc[x];
        while (!stk.empty()) {
            int y = stk.back(), a = anc[y];
            stk.pop_back();
            if (semi[label[a]] < semi[label[y]]) label[y] = label[a];
            anc[y] = anc[a];
        }
        return label[v];
    };
    for (int i = k - 1; i >= 1; i--) {
        int w = ord[i];
        for (int j = rs[w]; j < rs[w + 1]; j++) {
            int v = num[radj[j]];
            if (v < 0) continue;
            int u = semi[eval(v)];
            if (u < semi[i]) semi[i] = u;
        }
        anc[i] = dpar[i];
    }
    idom[0] = 0;
    for (int i = 1; i < k; i++) {
        int d = dpar[i];
        while (d > semi[i]) d = idom[d];
        idom[i] = d;
    }
    vector<int> par(n, -1);
    for (int i = 0; i < k; i++) par[ord[i]] = ord[idom[i]];
    return par;
}
