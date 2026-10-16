#define PROBLEM "https://judge.yosupo.jp/problem/counting_eulerian_circuits"
#include "../io/fastio.hpp"
#include "../math/modint.hpp"
#include "../graph/count_eulerian_circuits.hpp"

int main() {
    int n, m;
    fin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (auto &[a, b] : edges) fin >> a >> b;
    fout << count_eulerian_circuits<ModInt998244353>(n, edges) << '\n';
    return 0;
}
