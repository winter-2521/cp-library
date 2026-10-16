#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// 木幅 2 以下の判定と木分解．単純無向グラフについて O((n + m) 期待)
// 木幅 2 以下 ⇔ 「次数 0, 1 の頂点を消す」「次数 2 の頂点 v を消して，2 つの隣を辺で結ぶ (直列の縮約)」を繰り返して
// 全部消せる (多重辺は 1 本にまとめる)．消した順 (消去順序) から木分解を作る:
//   頂点 v を消したときのバッグ = {v} ∪ (そのときの隣)，その親 = 隣のうち先に消えたもののバッグ
// (v を消すときに隣どうしを結んでいるので，親のバッグに「v の隣のうち親以外」が必ず入っている)
// 返り値: 木幅 2 以下なら木分解 (頂点 v を消したときのバッグを bags[v] (先頭 bag_size[v] 個) とする．木の辺はバッグ番号の組)，
//         そうでなければ nullopt
struct TreeDecomposition {
    vector<array<int, 3>> bags;
    vector<int> bag_size;
    vector<pair<int, int>> edges;
};

inline optional<TreeDecomposition> tree_decomposition_width_2(int n, const vector<pair<int, int>> &edges) {
    // 辺の有無を調べる小さなハッシュ集合 (キー a * n + b，a < b)
    size_t cap = 1;
    while (cap < 2 * (edges.size() + n) + 2) cap <<= 1;
    vector<unsigned long long> table(cap, ~0ULL);
    auto hash = [&](unsigned long long x) {
        x ^= x >> 31, x *= 0x9e3779b97f4a7c15ULL, x ^= x >> 29;
        return x & (cap - 1);
    };
    // 入っていなければ入れて true
    auto insert = [&](int a, int b) {
        if (a > b) swap(a, b);
        unsigned long long key = (unsigned long long)a * n + b;
        for (size_t h = hash(key);; h = (h + 1) & (cap - 1)) {
            if (table[h] == key) return false;
            if (table[h] == ~0ULL) {
                table[h] = key;
                return true;
            }
        }
    };
    // 隣接は連結リスト (head, nxt, to) で持つ．後から足す辺も同じ配列に入れる
    vector<int> head(n, -1), nxt, to, deg(n, 0);
    nxt.reserve(2 * (edges.size() + n)), to.reserve(2 * (edges.size() + n));
    auto add_edge = [&](int a, int b) {
        to.push_back(b), nxt.push_back(head[a]), head[a] = to.size() - 1;
        to.push_back(a), nxt.push_back(head[b]), head[b] = to.size() - 1;
        deg[a]++, deg[b]++;
    };
    for (auto [a, b] : edges)
        if (a != b && insert(a, b)) add_edge(a, b);
    vector<char> dead(n, 0);
    vector<int> que, t(n, -1);
    for (int v = 0; v < n; v++)
        if (deg[v] <= 2) que.push_back(v);
    TreeDecomposition td;
    td.bags.assign(n, {-1, -1, -1});
    td.bag_size.assign(n, 0);
    int cnt = 0;
    while (!que.empty()) {
        int v = que.back();
        que.pop_back();
        if (dead[v] || deg[v] > 2) continue;
        auto &bag = td.bags[v];
        int k = 0;
        bag[k++] = v;
        for (int e = head[v]; e >= 0; e = nxt[e])
            if (!dead[to[e]]) bag[k++] = to[e];
        td.bag_size[v] = k;
        dead[v] = 1, t[v] = cnt++;
        for (int i = 1; i < k; i++) deg[bag[i]]--;
        if (k == 3 && insert(bag[1], bag[2])) add_edge(bag[1], bag[2]);
        for (int i = 1; i < k; i++)
            if (deg[bag[i]] <= 2) que.push_back(bag[i]);
    }
    if (cnt < n) return nullopt;
    // 親 = 隣のうち先に消えたもの．根 (隣なし) は 1 本の道でつなぐ
    td.edges.reserve(n);
    int prev_root = -1;
    for (int v = 0; v < n; v++) {
        const auto &bag = td.bags[v];
        int p = -1;
        for (int i = 1; i < td.bag_size[v]; i++)
            if (p < 0 || t[bag[i]] < t[p]) p = bag[i];
        if (p >= 0) {
            td.edges.push_back({v, p});
        } else {
            if (prev_root >= 0) td.edges.push_back({prev_root, v});
            prev_root = v;
        }
    }
    return td;
}
