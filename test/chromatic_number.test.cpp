#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_number"
#include "../io/fastio.hpp"
#include "../graph/chromatic.hpp"

int main() {
    int n, m;
    fin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (auto &[a, b] : edges) fin >> a >> b;
    fout << chromatic_number(n, edges) << '\n';
    return 0;
}
