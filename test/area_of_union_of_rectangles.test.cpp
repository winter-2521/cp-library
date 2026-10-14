#define PROBLEM "https://judge.yosupo.jp/problem/area_of_union_of_rectangles"
#include "../io/fastio.hpp"
#include "../data_structure/area_of_union_of_rectangles.hpp"

int main() {
    int n;
    fin >> n;
    vector<long long> l(n), d(n), r(n), u(n);
    for (int i = 0; i < n; i++) fin >> l[i] >> d[i] >> r[i] >> u[i];
    fout << area_of_union_of_rectangles(l, d, r, u) << '\n';
    return 0;
}
