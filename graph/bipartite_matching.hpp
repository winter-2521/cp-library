#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// 二部グラフの最大マッチング．O(m √n)
// 1. 初期マッチングは Karp-Sipser の貪欲 (次数 1 の頂点から組む) で作る
// 2. 左の未マッチ頂点全部から同時に BFS し，各頂点に「どの始点から来たか (root)」を付ける．
//    未マッチの右頂点に着いたらその場で増加し，同じ root の探索は打ち切る．1 回 O(m) で多数の増加路が取れ，実用上とても速い
// 3. 2 を √n 回やっても終わらなければ Hopcroft-Karp (層に沿った DFS で最短増加路をまとめて取る) に切り替えて O(m √n) を保証する
struct BipartiteMatching {
    int L, R;
    vector<pair<int, int>> edges;
    vector<int> match_l, match_r;  // 相手 (いなければ -1)

    BipartiteMatching(int L, int R) : L(L), R(R) {}
    void reserve(int m) { edges.reserve(m); }
    // 左 a と右 b の間に辺
    void add_edge(int a, int b) { edges.push_back({a, b}); }

    // 最大マッチングの大きさを返す
    int solve() {
        vector<int> start(L + 1, 0), adj(edges.size());
        for (auto &[a, b] : edges) start[a + 1]++;
        for (int i = 0; i < L; i++) start[i + 1] += start[i];
        {
            vector<int> pos(start.begin(), start.end() - 1);
            for (auto &[a, b] : edges) adj[pos[a]++] = b;
        }
        match_l.assign(L, -1), match_r.assign(R, -1);
        // 初期マッチング (Karp-Sipser): 残りの次数が 1 の頂点は，その唯一の相手と組ませても最大マッチングを損なわない．
        // そういう頂点があれば先に組み，なければ適当な頂点を組む．後の増加路の探索がずっと減る
        int res = 0;
        {
            vector<int> rstart(R + 1, 0), radj(edges.size());
            for (auto &[a, b] : edges) rstart[b + 1]++;
            for (int i = 0; i < R; i++) rstart[i + 1] += rstart[i];
            {
                vector<int> pos(rstart.begin(), rstart.end() - 1);
                for (auto &[a, b] : edges) radj[pos[b]++] = a;
            }
            // 頂点番号: 左 0..L-1，右 L..L+R-1
            vector<int> deg(L + R);
            for (int a = 0; a < L; a++) deg[a] = start[a + 1] - start[a];
            for (int b = 0; b < R; b++) deg[L + b] = rstart[b + 1] - rstart[b];
            vector<char> dead(L + R, 0);
            vector<int> ones;
            for (int x = 0; x < L + R; x++)
                if (deg[x] == 1) ones.push_back(x);
            auto remove = [&](int x) {  // x を取り除き，隣の次数を下げる
                dead[x] = 1;
                if (x < L) {
                    for (int i = start[x]; i < start[x + 1]; i++) {
                        int y = L + adj[i];
                        if (!dead[y] && --deg[y] == 1) ones.push_back(y);
                    }
                } else {
                    int b = x - L;
                    for (int i = rstart[b]; i < rstart[b + 1]; i++) {
                        int y = radj[i];
                        if (!dead[y] && --deg[y] == 1) ones.push_back(y);
                    }
                }
            };
            auto partner = [&](int x) {  // 生きている隣を 1 つ
                if (x < L) {
                    for (int i = start[x]; i < start[x + 1]; i++)
                        if (!dead[L + adj[i]]) return L + adj[i];
                } else {
                    int b = x - L;
                    for (int i = rstart[b]; i < rstart[b + 1]; i++)
                        if (!dead[radj[i]]) return radj[i];
                }
                return -1;
            };
            auto pair_up = [&](int x, int y) {
                int a = x < L ? x : y, b = (x < L ? y : x) - L;
                match_l[a] = b, match_r[b] = a, res++;
                remove(x), remove(y);
            };
            int scan = 0;
            while (true) {
                if (!ones.empty()) {
                    int x = ones.back();
                    ones.pop_back();
                    if (dead[x] || deg[x] != 1) continue;
                    int y = partner(x);
                    if (y >= 0) pair_up(x, y);
                    continue;
                }
                while (scan < L && (dead[scan] || deg[scan] == 0)) scan++;
                if (scan == L) break;
                int y = partner(scan);
                if (y < 0) {
                    dead[scan] = 1;
                    continue;
                }
                pair_up(scan, y);
            }
        }
        vector<int> que(L);
        {
            vector<int> root(L, -1), prev(L);
            int rounds = 0, lim_rounds = (int)sqrt((double)(L + R)) + 1;
            while (rounds++ < lim_rounds) {
                int qt = 0;
                for (int a = 0; a < L; a++)
                    if (match_l[a] < 0) root[a] = a, prev[a] = -1, que[qt++] = a;
                bool updated = false;
                for (int qh = 0; qh < qt; qh++) {
                    int a = que[qh];
                    if (match_l[root[a]] >= 0) continue;  // この始点はもう増加した
                    for (int i = start[a]; i < start[a + 1]; i++) {
                        int b = adj[i], c = match_r[b];
                        if (c < 0) {
                            // prev を遡りながら反転: a-b を組み，a の元の相手を prev[a] に渡す
                            while (b >= 0) {
                                int t = match_l[a];
                                match_l[a] = b, match_r[b] = a;
                                b = t, a = prev[a];
                            }
                            res++, updated = true;
                            break;
                        }
                        if (root[c] < 0) root[c] = root[a], prev[c] = a, que[qt++] = c;
                    }
                }
                for (int k = 0; k < qt; k++) root[que[k]] = -1;
                if (!updated) return res;
            }
        }
        vector<int> dist(L), it(L), stk;
        while (true) {
            // BFS: 左の未マッチ頂点を距離 0 として層を作る
            int qh = 0, qt = 0;
            for (int a = 0; a < L; a++) {
                if (match_l[a] < 0) dist[a] = 0, que[qt++] = a;
                else dist[a] = -1;
            }
            // 未マッチの右頂点に最初に届いた層 lim より深くは広げない (最短の増加路だけを使う)
            int lim = -1;
            while (qh < qt) {
                int a = que[qh++];
                if (lim >= 0 && dist[a] >= lim) break;
                for (int i = start[a]; i < start[a + 1]; i++) {
                    int c = match_r[adj[i]];
                    if (c < 0) {
                        if (lim < 0) lim = dist[a];
                    } else if (dist[c] < 0) {
                        dist[c] = dist[a] + 1, que[qt++] = c;
                    }
                }
            }
            if (lim < 0) break;
            // DFS (非再帰): 層を 1 つずつ下りる増加路
            for (int a = 0; a < L; a++) it[a] = start[a];
            for (int s = 0; s < L; s++) {
                if (match_l[s] >= 0) continue;
                stk.clear(), stk.push_back(s);
                while (!stk.empty()) {
                    int a = stk.back();
                    bool advanced = false;
                    while (it[a] < start[a + 1]) {
                        int b = adj[it[a]], c = match_r[b];
                        if (c < 0 && dist[a] == lim) {
                            // 増加路が見つかった: スタックに沿って反転
                            for (int k = (int)stk.size() - 1; k >= 0; k--) {
                                int x = stk[k], y = adj[it[x]];
                                match_l[x] = y, match_r[y] = x;
                            }
                            res++;
                            stk.clear();
                            advanced = true;
                            break;
                        }
                        if (c >= 0 && dist[c] == dist[a] + 1 && dist[a] < lim) {
                            stk.push_back(c);
                            advanced = true;
                            break;
                        }
                        it[a]++;
                    }
                    if (!advanced) {
                        dist[a] = -1;  // 行き止まり
                        stk.pop_back();
                        if (!stk.empty()) it[stk.back()]++;
                    }
                }
            }
        }
        return res;
    }

    // マッチングの辺 (左, 右) の列
    vector<pair<int, int>> matching() const {
        vector<pair<int, int>> res;
        for (int a = 0; a < L; a++)
            if (match_l[a] >= 0) res.push_back({a, match_l[a]});
        return res;
    }
};
