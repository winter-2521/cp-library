#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../data_structure/cumulative_sum.hpp"

// 1 次元・2 次元累積和を愚直と照合する

int main() {
    mt19937_64 rng(5);
    vector<int> a(50);
    for (auto &x : a) x = (int)(rng() % 2000000001) - 1000000000;
    CumulativeSum<long long> cs(a);
    for (int i = 0; i < 20; i++) {
        int x = rng() % 100;
        a.push_back(x);
        cs.push_back(x);
    }
    assert(cs.size() == (int)a.size());
    for (int l = 0; l <= (int)a.size(); l++) {
        for (int r = l; r <= (int)a.size(); r++) {
            long long s = 0;
            for (int i = l; i < r; i++) s += a[i];
            assert(cs.sum(l, r) == s);
        }
        long long s = 0;
        for (int i = 0; i < l; i++) s += a[i];
        assert(cs.prefix(l) == s);
    }
    for (auto [h, w] : vector<pair<int, int>>{{0, 0}, {1, 1}, {1, 7}, {6, 1}, {13, 17}}) {
        vector<vector<int>> g(h, vector<int>(w));
        for (auto &row : g) for (auto &x : row) x = (int)(rng() % 21) - 10;
        CumulativeSum2D<long long> c2(g);
        for (int x1 = 0; x1 <= h; x1++) for (int x2 = x1; x2 <= h; x2++) for (int y1 = 0; y1 <= w; y1++) for (int y2 = y1; y2 <= w; y2++) {
            long long s = 0;
            for (int i = x1; i < x2; i++) for (int j = y1; j < y2; j++) s += g[i][j];
            assert(c2.sum(x1, y1, x2, y2) == s);
        }
    }
    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
