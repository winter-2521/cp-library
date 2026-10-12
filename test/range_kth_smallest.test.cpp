#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include "../io/fastio.hpp"
#include "../data_structure/wavelet_matrix.hpp"

int main() {
    int n, q;
    fin >> n >> q;
    vector<int> a(n);
    fin >> a;
    WaveletMatrix<int> wm(a);
    while (q--) {
        int l, r, k;
        fin >> l >> r >> k;
        fout << wm.kth_smallest(l, r, k) << '\n';
    }
    return 0;
}
