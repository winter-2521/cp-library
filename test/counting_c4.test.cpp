#define PROBLEM "https://judge.yosupo.jp/problem/counting_c4"
#include "../io/fastio.hpp"
#include "../graph/counting_c4.hpp"

int main() {
    int n, m;
    fin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (auto &[a, b] : edges) fin >> a >> b;
    fout << counting_c4(n, edges) << '\n';
    return 0;
}
