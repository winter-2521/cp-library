#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../data_structure/static_rmq.hpp"
#include "../../data_structure/sparse_table.hpp"

// StaticRMQ (argmin は一番左の位置) と SparseTable を愚直と照合する

int main() {
    mt19937_64 rng(7);
    for (int n : {1, 2, 63, 64, 65, 127, 128, 129, 200, 300}) {
        for (int range : {3, 1000000}) {
            vector<int> a(n);
            for (auto &x : a) x = rng() % range;
            StaticRMQ<int> mn(a);
            StaticRMQ<int, greater<int>> mx(a);
            SparseTable st(a, [](int x, int y) { return gcd(x, y); });
            SparseTable smx(a, [](int x, int y) { return max(x, y); });
            for (int l = 0; l < n; l++) {
                int bmin = l, bmax = l, g = 0;
                for (int r = l + 1; r <= n; r++) {
                    if (a[r - 1] < a[bmin]) bmin = r - 1;
                    if (a[r - 1] > a[bmax]) bmax = r - 1;
                    g = gcd(g, a[r - 1]);
                    assert(mn.argmin(l, r) == bmin && mn.prod(l, r) == a[bmin]);
                    assert(mx.argmin(l, r) == bmax && mx.prod(l, r) == a[bmax]);
                    assert(st.prod(l, r) == g);
                    assert(smx.prod(l, r) == a[bmax]);
                }
            }
        }
    }
    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
