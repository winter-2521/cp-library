#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// グラフ G (n 頂点，重み付き無向) に新しい頂点 N と辺 {i, N} (重み a_i) を足したグラフ H の最小カットを，
// a_i を書き換えながら求める．
// H のカットは「N を含まない側 X ⊆ V (空でない)」で表せ，その重さは d_G(X) + a(X) (a(X) = Σ_{i∈X} a_i)．
// 1. 最小にする X は「極端集合」(真部分集合 Y が全て d(Y) > d(X) を満たす X) から選んでよい
//    (そうでない X は d(Y) <= d(X) かつ a(Y) <= a(X) の Y に替えられる)．極端集合は層状 (交わるなら包含関係) で
//    高々 2n - 1 個なので，それらを含む層状の族を木で持つ
// 2. 木は Nagamochi の「最小次数順序」で作る: 未訪問の頂点のうち「未訪問の頂点への辺の重みの和」が最小のものを順に選ぶと，
//    最後の 2 頂点を分ける極端集合は 1 頂点だけのものに限られるので，2 頂点を縮約して木の親を作る．これを n - 1 回
// 3. 各木のノード X に d_G(X) + a(X) を持たせ，a_i の変更は「葉 i から根までの道に加算」，答えは全体の最小値．
//    重軽分解 + 区間加算・全体最小のセグメント木で O(log^2 n)
// 構築 O(n (n + m) log n)，更新 O(log^2 n)
struct StarAugmentedMinCut {
    using ll = long long;
    int n, sz;
    vector<int> par, head, pos;  // 木 (ノード 0..n-1 が葉，n..2n-2 が縮約で作ったノード)
    vector<ll> a, st, lz;        // st: セグメント木 (min)，lz: そのノード全体に足した値

    StarAugmentedMinCut(int n_, const vector<tuple<int, int, ll>> &edges, const vector<ll> &a_) : n(n_), a(a_) {
        int K = 2 * n - 1;
        par.assign(K, -1);
        vector<array<int, 2>> ch(K, {-1, -1});
        // 1, 2. 最小次数順序で縮約して木を作る
        {
            vector<tuple<int, int, ll>> es;
            for (auto [u, v, w] : edges)
                if (u != v && w > 0) es.push_back({u, v, w});
            // 縮約後の頂点は 0..k-1 に詰めて持つ．node[c]: 頂点 c に対応する木のノード
            vector<int> node(n);
            iota(node.begin(), node.end(), 0);
            vector<int> start(n + 1);
            vector<pair<int, ll>> adj(2 * es.size());
            vector<ll> cost(n), selc(n), wz(n);
            vector<int> hpos_heap(n), hp(n, -1), ord;
            vector<char> inU(n);
            ord.reserve(n);
            int r = 0;  // ord[0..r) は前の段の順序がそのまま使える
            for (int step = 0; step < n - 1; step++) {
                int k = n - step;
                // 縮約後のグラフを CSR で
                fill(start.begin(), start.begin() + k + 1, 0);
                for (auto &[u, v, w] : es) start[u + 1]++, start[v + 1]++;
                for (int i = 0; i < k; i++) start[i + 1] += start[i];
                {
                    vector<int> p(start.begin(), start.begin() + k);
                    for (auto &[u, v, w] : es) adj[p[u]++] = {v, w}, adj[p[v]++] = {u, w};
                }
                // 最小次数順序の r 番目以降: cost[v] = (未訪問の頂点への辺の重みの和) が最小のものを順に選ぶ．
                // 位置つき二分ヒープで減少キー
                fill(inU.begin(), inU.begin() + k, 1);
                for (int i = 0; i < r; i++) inU[ord[i]] = 0;
                int hs = 0;
                for (int v = 0; v < k; v++) {
                    if (!inU[v]) continue;
                    cost[v] = 0;
                    for (int j = start[v]; j < start[v + 1]; j++)
                        if (inU[adj[j].first]) cost[v] += adj[j].second;
                    hpos_heap[hs] = v, hp[v] = hs++;
                }
                auto up = [&](int i) {
                    int x = hpos_heap[i];
                    while (i > 0) {
                        int p = (i - 1) >> 1;
                        if (cost[hpos_heap[p]] <= cost[x]) break;
                        hpos_heap[i] = hpos_heap[p], hp[hpos_heap[i]] = i, i = p;
                    }
                    hpos_heap[i] = x, hp[x] = i;
                };
                auto down = [&](int i) {
                    int x = hpos_heap[i];
                    while (true) {
                        int c = 2 * i + 1;
                        if (c >= hs) break;
                        if (c + 1 < hs && cost[hpos_heap[c + 1]] < cost[hpos_heap[c]]) c++;
                        if (cost[hpos_heap[c]] >= cost[x]) break;
                        hpos_heap[i] = hpos_heap[c], hp[hpos_heap[i]] = i, i = c;
                    }
                    hpos_heap[i] = x, hp[x] = i;
                };
                for (int i = hs / 2 - 1; i >= 0; i--) down(i);
                ord.resize(r);
                while (hs > 0) {
                    int v = hpos_heap[0];
                    hp[v] = -1;
                    if (--hs > 0) hpos_heap[0] = hpos_heap[hs], down(0);
                    selc[ord.size()] = cost[v], ord.push_back(v);
                    for (int j = start[v]; j < start[v + 1]; j++) {
                        auto [y, w] = adj[j];
                        if (hp[y] >= 0) cost[y] -= w, up(hp[y]);
                    }
                }
                // 最後の 2 つ x, y を縮約: y を x に付け替え，空いた y に最後の頂点 k-1 を移す
                int x = ord[k - 1], y = ord[k - 2], nd = n + step;
                ch[nd] = {node[x], node[y]}, par[node[x]] = par[node[y]] = nd;
                node[x] = nd, node[y] = node[k - 1];
                auto f = [&](int e) {
                    if (e == y) e = x;
                    return e == k - 1 ? y : e;
                };
                size_t t = 0;
                for (auto &[u, v, w] : es) {
                    int fu = f(u), fv = f(v);
                    if (fu != fv) es[t++] = {fu, fv, w};
                }
                es.resize(t);
                // 縮約した頂点 z 以外の頂点の「未訪問への重み」は縮約で変わらないので，順序の先頭は
                // 「z の未訪問への重みが，その段で選んだ頂点の値より小さくなる」最初の段 r まではそのまま使える
                int z = f(x);
                ord.resize(k - 2);
                for (auto &v : ord) v = f(v);
                fill(wz.begin(), wz.begin() + k - 1, 0);
                ll cz = 0;
                for (auto &[u, v, w] : es)
                    if (u == z) wz[v] += w, cz += w;
                    else if (v == z) wz[u] += w, cz += w;
                r = 0;
                while (r < k - 2 && cz >= selc[r]) cz -= wz[ord[r]], r++;
            }
        }
        // d_G(X): 辺 (u, v, w) は u, v から LCA の手前までのノードに w を足す (差分を葉から根へ累積)
        vector<int> dep(K, 0);
        for (int v = K - 2; v >= 0; v--) dep[v] = dep[par[v]] + 1;
        vector<ll> val(K, 0);
        for (auto [u, v, w] : edges) {
            if (u == v) continue;
            int x = u, y = v;
            while (x != y) {
                if (dep[x] < dep[y]) swap(x, y);
                x = par[x];
            }
            val[u] += w, val[v] += w, val[x] -= 2 * w;
        }
        for (int i = 0; i < n; i++) val[i] += a[i];
        for (int v = 0; v < K - 1; v++) val[par[v]] += val[v];  // 子の番号 < 親の番号
        // 3. 重軽分解 (根 K-1)
        vector<int> sub(K, 1), heavy(K, -1);
        for (int v = 0; v < K - 1; v++) sub[par[v]] += sub[v];
        for (int v = K - 1; v >= n; v--) heavy[v] = sub[ch[v][0]] >= sub[ch[v][1]] ? ch[v][0] : ch[v][1];
        head.assign(K, 0), pos.assign(K, 0);
        {
            int cur = 0;
            vector<int> stk{K - 1};
            head[K - 1] = K - 1;
            while (!stk.empty()) {
                int h = stk.back();
                stk.pop_back();
                for (int v = h; v >= 0; v = heavy[v]) {
                    head[v] = h, pos[v] = cur++;
                    if (v >= n)
                        for (int c : ch[v])
                            if (c != heavy[v]) stk.push_back(c);
                }
            }
        }
        sz = 1;
        while (sz < K) sz <<= 1;
        st.assign(2 * sz, numeric_limits<ll>::max() / 4), lz.assign(2 * sz, 0);
        for (int v = 0; v < K; v++) st[sz + pos[v]] = val[v];
        for (int i = sz - 1; i >= 1; i--) st[i] = std::min(st[2 * i], st[2 * i + 1]);
    }

    // a_x を y に変える
    void set(int x, ll y) {
        ll d = y - a[x];
        a[x] = y;
        for (int v = x; v >= 0; v = par[head[v]]) range_add(pos[head[v]], pos[v] + 1, d);
    }
    // 今の H の最小カット
    ll min_cut() const { return st[1]; }

  private:
    void apply(int k, ll x) { st[k] += x, lz[k] += x; }
    void pull(int k) {
        for (k >>= 1; k >= 1; k >>= 1) st[k] = std::min(st[2 * k], st[2 * k + 1]) + lz[k];
    }
    void range_add(int l, int r, ll x) {
        int l0 = l + sz, r0 = r - 1 + sz;
        for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
            if (l & 1) apply(l++, x);
            if (r & 1) apply(--r, x);
        }
        pull(l0), pull(r0);
    }
};
