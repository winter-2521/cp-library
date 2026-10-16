#define PROBLEM "https://judge.yosupo.jp/problem/directedmst"
#include "../io/fastio.hpp"
#include "../graph/directed_mst.hpp"

int main() {
    int n, m, s;
    fin >> n >> m >> s;
    vector<tuple<int, int, long long>> edges(m);
    for (auto &[a, b, c] : edges) fin >> a >> b >> c;
    auto [x, par] = directed_mst(n, edges, s);
    fout << x << '\n' << par << '\n';
    return 0;
}
