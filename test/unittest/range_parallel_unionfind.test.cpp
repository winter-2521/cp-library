#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../data_structure/range_parallel_unionfind.hpp"

// RangeParallelUnionFind を愚直 (1 本ずつ併合) と照合する

int main() {
    mt19937_64 rng(9);
    for (int n : {1, 2, 3, 10, 64, 200}) {
        RangeParallelUnionFind uf(n);
        vector<int> comp(n);
        iota(comp.begin(), comp.end(), 0);
        int merges = 0;
        for (int it = 0; it < 300; it++) {
            int k = rng() % (n + 1);
            if (rng() % 3 == 0) k = min<int>(n, rng() % 3);
            int a = rng() % (n - k + 1), b = rng() % (n - k + 1);
            uf.merge(a, b, k, [&](int r, int c) {
                assert(uf.leader(c) == r);
                merges++;
            });
            for (int i = 0; i < k; i++) {
                int ca = comp[a + i], cb = comp[b + i];
                if (ca != cb) for (auto &c : comp) if (c == cb) c = ca;
            }
            set<int> kinds(comp.begin(), comp.end());
            assert(merges == n - (int)kinds.size());
            for (int t = 0; t < 50; t++) {
                int x = rng() % n, y = rng() % n;
                assert(uf.same(x, y) == (comp[x] == comp[y]));
                assert(uf.size(x) == count(comp.begin(), comp.end(), comp[x]));
            }
        }
    }
    // merge_offline: 時刻ごとの併合回数がオンライン版と一致し，コールバックの併合だけで連結性が再現できる
    for (int n : {1, 2, 3, 10, 64, 200, 1000}) {
        for (int rep = 0; rep < 5; rep++) {
            int q = 300;
            vector<array<int, 3>> qs(q);
            RangeParallelUnionFind uf(n);
            vector<int> cnt_on(q, 0), cnt_off(q, 0);
            for (int t = 0; t < q; t++) {
                int k = rng() % (n + 1);
                if (rng() % 2 == 0) k = min<int>(n, rng() % 5);
                int a = rng() % (n - k + 1), b = rng() % (n - k + 1);
                qs[t] = {a, b, k};
                uf.merge(a, b, k, [&](int, int) { cnt_on[t]++; });
            }
            vector<int> par(n);
            iota(par.begin(), par.end(), 0);
            auto find = [&](auto self, int x) -> int { return par[x] == x ? x : par[x] = self(self, par[x]); };
            int last = -1;
            RangeParallelUnionFind::merge_offline(n, qs, [&](int t, int r, int c) {
                assert(last <= t);
                last = t;
                cnt_off[t]++;
                int x = find(find, r), y = find(find, c);
                assert(x != y);
                par[y] = x;
            });
            assert(cnt_on == cnt_off);
            for (int x = 0; x < n; x++) assert((find(find, x) == find(find, 0)) == uf.same(x, 0));
        }
    }

    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
