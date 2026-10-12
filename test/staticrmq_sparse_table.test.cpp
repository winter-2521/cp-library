#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../io/fastio.hpp"
#include "../data_structure/sparse_table.hpp"

int main() {
    int n, q;
    fin >> n >> q;
    vector<int> a(n);
    fin >> a;
    SparseTable st(a, [](int x, int y) { return x < y ? x : y; });
    while (q--) {
        int l, r;
        fin >> l >> r;
        fout << st.prod(l, r) << '\n';
    }
    return 0;
}
