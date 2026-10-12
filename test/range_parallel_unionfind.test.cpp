#define PROBLEM "https://judge.yosupo.jp/problem/range_parallel_unionfind"
#include "../io/fastio.hpp"
#include "../math/modint.hpp"
#include "../data_structure/range_parallel_unionfind.hpp"

using mint = ModInt998244353;

// クエリを先読みする高速版 (オンライン版は range_parallel_unionfind_online.test.cpp)
int main() {
    int n, q;
    fin >> n >> q;
    vector<mint> sum(n);
    fin >> sum;
    vector<array<int, 3>> qs(q);
    for (auto &[a, b, k] : qs) fin >> k >> a >> b;
    // 時刻 t の併合で増えた分
    vector<mint> add(q);
    RangeParallelUnionFind::merge_offline(n, qs, [&](int t, int r, int c) {
        add[t] += sum[r] * sum[c];
        sum[r] += sum[c];
    });
    mint ans = 0;
    for (int t = 0; t < q; t++) {
        ans += add[t];
        fout << ans << '\n';
    }
    return 0;
}
