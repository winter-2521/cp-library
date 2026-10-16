#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// 一般グラフの最大重みマッチング (Edmonds の主双対法・花の縮約)．O(n^3)
// 頂点ラベル (双対変数) lab と，花 (奇閉路を縮約した頂点) ごとのラベルを持ち，
// 「ラベルの和 = 辺の重み × 2」となる辺 (タイトな辺) だけで交互木を伸ばす．伸ばせなくなったら双対を d だけ動かす．
// 頂点は内部で 1-indexed，花は n+1 .. 2n
template <class W = long long>
struct GeneralWeightedMatching {
    struct Edge {
        int u, v;
        W w;
    };
    int n, nx;
    vector<vector<Edge>> g;
    vector<W> lab;
    vector<int> mate, slack, st, pa, S, vis;
    vector<vector<int>> flo_from;
    vector<vector<int>> flo;
    vector<int> que;
    size_t qh = 0;
    int vis_t = 0;

    GeneralWeightedMatching(int n_)
        : n(n_), nx(n_), g(2 * n_ + 1, vector<Edge>(2 * n_ + 1)), lab(2 * n_ + 1), mate(2 * n_ + 1), slack(2 * n_ + 1), st(2 * n_ + 1),
          pa(2 * n_ + 1), S(2 * n_ + 1), vis(2 * n_ + 1), flo_from(2 * n_ + 1, vector<int>(n_ + 1)), flo(2 * n_ + 1) {
        for (int u = 1; u <= n; u++)
            for (int v = 1; v <= n; v++) g[u][v] = {u, v, 0};
    }

    // 辺 (u, v) 重み w (0-indexed，w > 0．同じ組は重い方)
    void add_edge(int u, int v, W w) {
        u++, v++;
        if (w > g[u][v].w) g[u][v].w = g[v][u].w = w;
    }

    // {重みの和, マッチングの辺の数}
    pair<W, int> solve() {
        fill(mate.begin(), mate.end(), 0);
        nx = n;
        for (int u = 0; u <= n; u++) st[u] = u, flo[u].clear();
        W wmax = 0;
        for (int u = 1; u <= n; u++)
            for (int v = 1; v <= n; v++) {
                flo_from[u][v] = (u == v ? u : 0);
                wmax = std::max(wmax, g[u][v].w);
            }
        for (int u = 1; u <= n; u++) lab[u] = wmax;
        int cnt = 0;
        while (matching()) cnt++;
        W tot = 0;
        for (int u = 1; u <= n; u++)
            if (mate[u] && mate[u] < u) tot += g[u][mate[u]].w;
        return {tot, cnt};
    }

    // マッチングの辺 (0-indexed, u < v)
    vector<pair<int, int>> matching_edges() const {
        vector<pair<int, int>> res;
        for (int u = 1; u <= n; u++)
            if (mate[u] && u < mate[u]) res.push_back({u - 1, mate[u] - 1});
        return res;
    }

  private:
    W e_delta(const Edge &e) const { return lab[e.u] + lab[e.v] - g[e.u][e.v].w * 2; }
    void update_slack(int u, int x) {
        if (!slack[x] || e_delta(g[u][x]) < e_delta(g[slack[x]][x])) slack[x] = u;
    }
    void set_slack(int x) {
        slack[x] = 0;
        for (int u = 1; u <= n; u++)
            if (g[u][x].w > 0 && st[u] != x && S[st[u]] == 0) update_slack(u, x);
    }
    void q_push(int x) {
        if (x <= n) que.push_back(x);
        else
            for (int y : flo[x]) q_push(y);
    }
    void set_st(int x, int b) {
        st[x] = b;
        if (x > n)
            for (int y : flo[x]) set_st(y, b);
    }
    int get_pr(int b, int xr) {
        int pr = find(flo[b].begin(), flo[b].end(), xr) - flo[b].begin();
        if (pr % 2 == 1) {
            reverse(flo[b].begin() + 1, flo[b].end());
            return (int)flo[b].size() - pr;
        }
        return pr;
    }
    void set_match(int u, int v) {
        mate[u] = g[u][v].v;
        if (u <= n) return;
        Edge e = g[u][v];
        int xr = flo_from[u][e.u], pr = get_pr(u, xr);
        for (int i = 0; i < pr; i++) set_match(flo[u][i], flo[u][i ^ 1]);
        set_match(xr, v);
        rotate(flo[u].begin(), flo[u].begin() + pr, flo[u].end());
    }
    void augment(int u, int v) {
        while (true) {
            int xnv = st[mate[u]];
            set_match(u, v);
            if (!xnv) return;
            set_match(xnv, st[pa[xnv]]);
            u = st[pa[xnv]], v = xnv;
        }
    }
    int get_lca(int u, int v) {
        for (++vis_t; u || v; swap(u, v)) {
            if (u == 0) continue;
            if (vis[u] == vis_t) return u;
            vis[u] = vis_t;
            u = st[mate[u]];
            if (u) u = st[pa[u]];
        }
        return 0;
    }
    void add_blossom(int u, int lca, int v) {
        int b = n + 1;
        while (b <= nx && st[b]) b++;
        if (b > nx) nx++;
        lab[b] = 0, S[b] = 0;
        mate[b] = mate[lca];
        flo[b].clear();
        flo[b].push_back(lca);
        for (int x = u, y; x != lca; x = st[pa[y]]) flo[b].push_back(x), flo[b].push_back(y = st[mate[x]]), q_push(y);
        reverse(flo[b].begin() + 1, flo[b].end());
        for (int x = v, y; x != lca; x = st[pa[y]]) flo[b].push_back(x), flo[b].push_back(y = st[mate[x]]), q_push(y);
        set_st(b, b);
        for (int x = 1; x <= nx; x++) g[b][x].w = g[x][b].w = 0;
        for (int x = 1; x <= n; x++) flo_from[b][x] = 0;
        for (int xs : flo[b]) {
            for (int x = 1; x <= nx; x++)
                if (g[b][x].w == 0 || e_delta(g[xs][x]) < e_delta(g[b][x])) g[b][x] = g[xs][x], g[x][b] = g[x][xs];
            for (int x = 1; x <= n; x++)
                if (flo_from[xs][x]) flo_from[b][x] = xs;
        }
        set_slack(b);
    }
    void expand_blossom(int b) {
        for (int x : flo[b]) set_st(x, x);
        int xr = flo_from[b][g[b][pa[b]].u], pr = get_pr(b, xr);
        for (int i = 0; i < pr; i += 2) {
            int xs = flo[b][i], xns = flo[b][i + 1];
            pa[xs] = g[xns][xs].u;
            S[xs] = 1, S[xns] = 0;
            slack[xs] = 0, set_slack(xns);
            q_push(xns);
        }
        S[xr] = 1, pa[xr] = pa[b];
        for (size_t i = pr + 1; i < flo[b].size(); i++) {
            int xs = flo[b][i];
            S[xs] = -1, set_slack(xs);
        }
        st[b] = 0;
    }
    bool on_found_edge(const Edge &e) {
        int u = st[e.u], v = st[e.v];
        if (S[v] == -1) {
            pa[v] = e.u, S[v] = 1;
            int nu = st[mate[v]];
            slack[v] = slack[nu] = 0;
            S[nu] = 0, q_push(nu);
        } else if (S[v] == 0) {
            int lca = get_lca(u, v);
            if (!lca) {
                augment(u, v), augment(v, u);
                return true;
            }
            add_blossom(u, lca, v);
        }
        return false;
    }
    bool matching() {
        for (int x = 1; x <= nx; x++) S[x] = -1, slack[x] = 0;
        que.clear(), qh = 0;
        for (int x = 1; x <= nx; x++)
            if (st[x] == x && !mate[x]) pa[x] = 0, S[x] = 0, q_push(x);
        if (que.empty()) return false;
        while (true) {
            while (qh < que.size()) {
                int u = que[qh++];
                if (S[st[u]] == 1) continue;
                for (int v = 1; v <= n; v++) {
                    if (g[u][v].w > 0 && st[u] != st[v]) {
                        if (e_delta(g[u][v]) == 0) {
                            if (on_found_edge(g[u][v])) return true;
                        } else {
                            update_slack(u, st[v]);
                        }
                    }
                }
            }
            W d = numeric_limits<W>::max();
            for (int b = n + 1; b <= nx; b++)
                if (st[b] == b && S[b] == 1) d = std::min(d, lab[b] / 2);
            for (int x = 1; x <= nx; x++) {
                if (st[x] == x && slack[x]) {
                    if (S[x] == -1) d = std::min(d, e_delta(g[slack[x]][x]));
                    else if (S[x] == 0) d = std::min(d, e_delta(g[slack[x]][x]) / 2);
                }
            }
            // 外側の頂点のラベルが 0 になるなら，これ以上重みを増やせない (先に判定してから動かす)
            for (int u = 1; u <= n; u++)
                if (S[st[u]] == 0 && lab[u] <= d) return false;
            for (int u = 1; u <= n; u++) {
                if (S[st[u]] == 0) lab[u] -= d;
                else if (S[st[u]] == 1) lab[u] += d;
            }
            for (int b = n + 1; b <= nx; b++) {
                if (st[b] == b) {
                    if (S[st[b]] == 0) lab[b] += d * 2;
                    else if (S[st[b]] == 1) lab[b] -= d * 2;
                }
            }
            que.clear(), qh = 0;
            for (int x = 1; x <= nx; x++)
                if (st[x] == x && slack[x] && st[slack[x]] != x && e_delta(g[slack[x]][x]) == 0)
                    if (on_found_edge(g[slack[x]][x])) return true;
            for (int b = n + 1; b <= nx; b++)
                if (st[b] == b && S[b] == 1 && lab[b] == 0) expand_blossom(b);
        }
        return false;
    }
};
