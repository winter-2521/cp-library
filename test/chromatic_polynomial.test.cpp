#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_polynomial"
#include "../io/fastio.hpp"
#include "../math/modint.hpp"
#include "../graph/chromatic.hpp"

int main() {
    int n, m;
    fin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (auto &[a, b] : edges) fin >> a >> b;
    fout << chromatic_polynomial<ModInt998244353>(n, edges) << '\n';
    return 0;
}
