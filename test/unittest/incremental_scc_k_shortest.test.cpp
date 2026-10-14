#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../graph/incremental_scc.hpp"
#include "../../graph/k_shortest_walk.hpp"

// incremental_scc を「辺を 1 本ずつ足して到達可能性を計算し直す」愚直と，
// k_shortest_walks を「ウォークを優先度付きキューで全部列挙する」愚直と照合する

int main() {
    mt19937_64 rng(37);
    for (int it = 0; it < 2000; it++) {
        int n = rng() % 6 + 1, m = rng() % 12;
        vector<pair<int, int>> es(m);
        for (auto &[a, b] : es) a = rng() % n, b = rng() % n;
        auto t = incremental_scc(n, es);
        vector<int> exp(m, m + 1);
        vector<vector<char>> reach(n, vector<char>(n, 0));
        for (int i = 0; i < n; i++) reach[i][i] = 1;
        for (int k = 1; k <= m; k++) {
            auto [a, b] = es[k - 1];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (reach[i][a] && reach[b][j]) reach[i][j] = 1;
            for (int e = 0; e < k; e++)
                if (exp[e] == m + 1 && reach[es[e].first][es[e].second] && reach[es[e].second][es[e].first]) exp[e] = k;
        }
        assert(t == exp);
    }
    for (int it = 0; it < 2000; it++) {
        int n = rng() % 5 + 1, m = rng() % 8, K = rng() % 30 + 1;
        vector<tuple<int, int, long long>> es(m);
        for (auto &[a, b, c] : es) a = rng() % n, b = rng() % n, c = rng() % 4 + 1;
        int s = rng() % n, t = rng() % n;
        auto res = k_shortest_walks(n, es, s, t, K);
        // 愚直: (長さ, 頂点) を取り出すたびに全ての辺で伸ばす．t を取り出した順が答え
        vector<long long> exp;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, s});
        int pops = 0;
        while (!pq.empty() && (int)exp.size() < K && pops < 20000) {
            auto [d, v] = pq.top();
            pq.pop();
            pops++;
            if (v == t) exp.push_back(d);
            for (auto [a, b, c] : es)
                if (a == v) pq.push({d + c, b});
        }
        if (pops >= 20000) continue;  // 愚直が終わらないケースは飛ばす
        assert(res == exp);
    }
    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
