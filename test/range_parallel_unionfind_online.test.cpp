#define PROBLEM "https://judge.yosupo.jp/problem/range_parallel_unionfind"
#include "../io/fastio.hpp"
#include "../math/modint.hpp"
#include "../data_structure/range_parallel_unionfind.hpp"

using mint = ModInt998244353;

// オンライン版 (クエリごとに merge を呼ぶ)

int main() {
    int n, q;
    fin >> n >> q;
    vector<mint> sum(n);
    fin >> sum;
    RangeParallelUnionFind uf(n);
    mint ans = 0;
    while (q--) {
        int k, a, b;
        fin >> k >> a >> b;
        uf.merge(a, b, k, [&](int r, int c) {
            ans += sum[r] * sum[c];
            sum[r] += sum[c];
        });
        fout << ans << '\n';
    }
    return 0;
}
