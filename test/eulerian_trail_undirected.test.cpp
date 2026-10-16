#define PROBLEM "https://judge.yosupo.jp/problem/eulerian_trail_undirected"
#include "../io/fastio.hpp"
#include "../graph/eulerian_trail.hpp"

int main() {
    int T;
    fin >> T;
    while (T--) {
        int n, m;
        fin >> n >> m;
        vector<pair<int, int>> edges(m);
        for (auto &[a, b] : edges) fin >> a >> b;
        auto [vs, es] = eulerian_trail<false>(n, edges);
        if (vs.empty()) {
            fout << "No\n";
            continue;
        }
        fout << "Yes\n" << vs << '\n' << es << '\n';
    }
    return 0;
}
