#define PROBLEM "https://judge.yosupo.jp/problem/assignment"
#include "../io/fastio.hpp"
#include "../graph/hungarian.hpp"

int main() {
    int n;
    fin >> n;
    vector<vector<long long>> a(n, vector<long long>(n));
    for (auto &row : a) fin >> row;
    auto [x, p] = hungarian(a);
    fout << x << '\n' << p << '\n';
    return 0;
}
