#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../io/fastio.hpp"
#include "../data_structure/static_rmq.hpp"

int main() {
    int n, q;
    fin >> n >> q;
    vector<int> a(n);
    fin >> a;
    StaticRMQ<int> rmq(a);
    while (q--) {
        int l, r;
        fin >> l >> r;
        fout << rmq.prod(l, r) << '\n';
    }
    return 0;
}
