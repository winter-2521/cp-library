#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../data_structure/linear_add_min_segment_tree.hpp"

// LinearAddMinSegmentTree を愚直と照合する (値の幅を小さくして共線な点を多くする)

int main() {
    mt19937_64 rng(1);
    for (int n : {1, 2, 3, 4, 5, 7, 8, 13, 32, 50}) {
        for (int range : {1, 3, 1000}) {
            vector<long long> a(n);
            for (auto &x : a) x = (long long)(rng() % (2 * range + 1)) - range;
            LinearAddMinSegmentTree<long long> mn(a);
            LinearAddMinSegmentTree<long long, true> mx(a);
            for (int it = 0; it < 3000; it++) {
                int t = rng() % 4, l = rng() % n, r = rng() % n;
                if (l > r) swap(l, r);
                r++;
                if (t == 0) {
                    long long b = (long long)(rng() % 5) - 2, c = (long long)(rng() % 7) - 3;
                    for (int i = l; i < r; i++) a[i] += b * i + c;
                    mn.add(l, r, b, c), mx.add(l, r, b, c);
                } else if (t == 1) {
                    assert(mn.min(l, r) == *min_element(a.begin() + l, a.begin() + r));
                    assert(mx.max(l, r) == *max_element(a.begin() + l, a.begin() + r));
                } else if (t == 2) {
                    int i = rng() % n;
                    a[i] = (long long)(rng() % (2 * range + 1)) - range;
                    mn.set(i, a[i]), mx.set(i, a[i]);
                } else {
                    int i = rng() % n;
                    assert(mn.get(i) == a[i] && mx.get(i) == a[i]);
                    assert(mn.all_min() == *min_element(a.begin(), a.end()));
                }
            }
        }
    }
    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
