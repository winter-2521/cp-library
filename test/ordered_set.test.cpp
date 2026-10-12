#define PROBLEM "https://judge.yosupo.jp/problem/ordered_set"
#include "../io/fastio.hpp"
#include "../data_structure/fast_set.hpp"
#include "../data_structure/fenwick_tree.hpp"

// 挿入されうる値を先読みして座標圧縮し，FastSet (前後の要素) と FenwickTree (順位) を併用する

int main() {
    int n, q;
    fin >> n >> q;
    vector<int> a(n);
    fin >> a;
    vector<int> t(q), x(q);
    vector<int> vals = a;
    for (int i = 0; i < q; i++) {
        fin >> t[i] >> x[i];
        if (t[i] == 0) vals.push_back(x[i]);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int m = vals.size();
    auto idx = [&](int v) { return int(lower_bound(vals.begin(), vals.end(), v) - vals.begin()); };

    vector<int> init(m, 0);
    for (int v : a) init[idx(v)] = 1;
    FastSet fs(m, [&](int i) { return init[i] == 1; });
    FenwickTree<int> bit(init);
    int cnt = n;

    for (int i = 0; i < q; i++) {
        int v = x[i];
        if (t[i] == 0) {
            int p = idx(v);
            if (!fs.contains(p)) fs.insert(p), bit.add(p, 1), cnt++;
        } else if (t[i] == 1) {
            int p = idx(v);
            if (p < m && vals[p] == v && fs.contains(p)) fs.erase(p), bit.add(p, -1), cnt--;
        } else if (t[i] == 2) {
            fout << (cnt < v ? -1 : vals[bit.lower_bound(v)]) << '\n';
        } else if (t[i] == 3) {
            int p = int(upper_bound(vals.begin(), vals.end(), v) - vals.begin());
            fout << bit.sum(p) << '\n';
        } else if (t[i] == 4) {
            int p = int(upper_bound(vals.begin(), vals.end(), v) - vals.begin());
            int r = fs.prev(p - 1);
            fout << (r < 0 ? -1 : vals[r]) << '\n';
        } else {
            int r = fs.next(idx(v));
            fout << (r >= m ? -1 : vals[r]) << '\n';
        }
    }
    return 0;
}
