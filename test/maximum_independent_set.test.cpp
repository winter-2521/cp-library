#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"
#include "../io/fastio.hpp"
#include "../graph/maximum_independent_set.hpp"

int main() {
    int n, m;
    fin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (auto &[a, b] : edges) fin >> a >> b;
    auto s = maximum_independent_set(n, edges);
    fout << s.size() << '\n' << s << '\n';
    return 0;
}
