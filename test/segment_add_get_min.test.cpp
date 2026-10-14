#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"
#include "../io/fastio.hpp"
#include "../data_structure/li_chao_tree.hpp"

int main() {
    int n, q;
    fin >> n >> q;
    DynamicLiChaoTree<long long> lct(-1000000000, 1000000001);
    for (int i = 0; i < n; i++) {
        long long l, r, a, b;
        fin >> l >> r >> a >> b;
        lct.add_segment(l, r, a, b);
    }
    while (q--) {
        int t;
        fin >> t;
        if (t == 0) {
            long long l, r, a, b;
            fin >> l >> r >> a >> b;
            lct.add_segment(l, r, a, b);
        } else {
            long long p;
            fin >> p;
            long long y = lct.get(p);
            if (y == numeric_limits<long long>::max()) fout << "INFINITY\n";
            else fout << y << '\n';
        }
    }
    return 0;
}
