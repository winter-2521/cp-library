#define PROBLEM "https://judge.yosupo.jp/problem/k_shortest_walk"
#include "../io/fastio.hpp"
#include "../graph/k_shortest_walk.hpp"

int main() {
    int n, m, s, t, k;
    fin >> n >> m >> s >> t >> k;
    vector<tuple<int, int, long long>> edges(m);
    for (auto &[a, b, c] : edges) fin >> a >> b >> c;
    auto res = k_shortest_walks(n, edges, s, t, k);
    for (int i = 0; i < k; i++) fout << (i < (int)res.size() ? res[i] : -1) << '\n';
    return 0;
}
