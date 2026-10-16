#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// 重軽分解 (Heavy-Light Decomposition)．根付き木を「重い道」(各頂点から部分木が最大の子へ進む道) に分ける．
// 頂点を「重い子を先に訪れる DFS の行きがけ順」に並べると
//   - 部分木 = 区間 [in[v], out[v])
//   - 根から任意の頂点への道は O(log n) 本の重い道 (= 区間) に分かれる
// 構築 O(n)，LCA・距離・k 個上の祖先・道の k 番目は O(log n)
// 頂点 v の番号は in[v]，in の順の頂点列は ord
struct HLD {
    int n;
    vector<int> par, dep, sz, heavy, head, in, out, ord;

    HLD() = default;
    // 木の辺 (n - 1 本) と根から作る
    HLD(int n, const vector<pair<int, int>> &edges, int root = 0) : n(n) {
        vector<int> start(n + 1, 0), adj(2 * (n - 1));
        for (auto [a, b] : edges) start[a + 1]++, start[b + 1]++;
        for (int i = 0; i < n; i++) start[i + 1] += start[i];
        {
            vector<int> p(start.begin(), start.end() - 1);
            for (auto [a, b] : edges) adj[p[a]++] = b, adj[p[b]++] = a;
        }
        // BFS 順で親と深さ
        par.assign(n, -1), dep.assign(n, 0);
        vector<int> bfs;
        bfs.reserve(n);
        bfs.push_back(root);
        par[root] = -1;
        for (int i = 0; i < (int)bfs.size(); i++) {
            int v = bfs[i];
            for (int j = start[v]; j < start[v + 1]; j++) {
                int w = adj[j];
                if (w != par[v]) par[w] = v, dep[w] = dep[v] + 1, bfs.push_back(w);
            }
        }
        build(bfs, [&](int v, auto f) {
            for (int j = start[v]; j < start[v + 1]; j++)
                if (adj[j] != par[v]) f(adj[j]);
        });
    }
    // 親の配列から作る (par[root] = -1)
    explicit HLD(const vector<int> &parent) : n(parent.size()) {
        par = parent;
        vector<int> start(n + 1, 0), ch(n);
        int root = -1;
        for (int v = 0; v < n; v++)
            if (par[v] < 0) root = v;
            else start[par[v] + 1]++;
        for (int i = 0; i < n; i++) start[i + 1] += start[i];
        {
            vector<int> p(start.begin(), start.end() - 1);
            for (int v = 0; v < n; v++)
                if (par[v] >= 0) ch[p[par[v]]++] = v;
        }
        dep.assign(n, 0);
        vector<int> bfs;
        bfs.reserve(n);
        bfs.push_back(root);
        for (int i = 0; i < (int)bfs.size(); i++) {
            int v = bfs[i];
            for (int j = start[v]; j < start[v + 1]; j++) dep[ch[j]] = dep[v] + 1, bfs.push_back(ch[j]);
        }
        build(bfs, [&](int v, auto f) {
            for (int j = start[v]; j < start[v + 1]; j++) f(ch[j]);
        });
    }

    int lca(int u, int v) const {
        while (head[u] != head[v]) {
            if (in[head[u]] > in[head[v]]) u = par[head[u]];
            else v = par[head[v]];
        }
        return in[u] < in[v] ? u : v;
    }
    int dist(int u, int v) const { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }
    // v から k 個上の祖先 (なければ -1)
    int la(int v, int k) const {
        if (k > dep[v]) return -1;
        while (true) {
            int h = head[v];
            if (in[v] - in[h] >= k) return ord[in[v] - k];
            k -= in[v] - in[h] + 1;
            v = par[h];
        }
    }
    // s から t への道 (s = v_0, ..., v_d = t) の v_i (i > d なら -1)
    int jump(int s, int t, int i) const {
        int w = lca(s, t), ds = dep[s] - dep[w], d = ds + dep[t] - dep[w];
        if (i > d) return -1;
        return i <= ds ? la(s, i) : la(t, d - i);
    }
    // u - v の道を in の区間 [l, r) の列に分ける (頂点の道．順不同)
    template <class F>
    void path(int u, int v, F f) const {
        while (head[u] != head[v]) {
            if (in[head[u]] > in[head[v]]) swap(u, v);
            f(in[head[v]], in[v] + 1);
            v = par[head[v]];
        }
        if (in[u] > in[v]) swap(u, v);
        f(in[u], in[v] + 1);
    }
    // 部分木の区間 [in[v], out[v])
    pair<int, int> subtree(int v) const { return {in[v], out[v]}; }

  private:
    // bfs: BFS 順の頂点列．children(v, f): v の子 c ごとに f(c)
    template <class C>
    void build(const vector<int> &bfs, C children) {
        sz.assign(n, 1), heavy.assign(n, -1);
        for (int i = n - 1; i > 0; i--) {
            int v = bfs[i], p = par[v];
            sz[p] += sz[v];
        }
        for (int i = n - 1; i >= 0; i--) {
            int v = bfs[i], best = 0;
            children(v, [&](int c) {
                if (sz[c] > best) best = sz[c], heavy[v] = c;
            });
        }
        // 重い子を先に訪れる行きがけ順 (非再帰)．重い道は連続した番号になる
        head.assign(n, 0), in.assign(n, 0), out.assign(n, 0), ord.assign(n, 0);
        int cur = 0;
        vector<int> stk{bfs[0]};
        head[bfs[0]] = bfs[0];
        while (!stk.empty()) {
            int h = stk.back();
            stk.pop_back();
            // h から重い道を下りながら番号を振り，軽い子を積む
            for (int v = h; v >= 0; v = heavy[v]) {
                head[v] = h, in[v] = cur, ord[cur++] = v;
                children(v, [&](int c) {
                    if (c != heavy[v]) stk.push_back(c);
                });
            }
        }
        for (int v = 0; v < n; v++) out[v] = in[v] + sz[v];
    }
};
