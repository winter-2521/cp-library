#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include "../io/fastio.hpp"
#include "../data_structure/li_chao_tree.hpp"

int main() {
    int n, q;
    fin >> n >> q;
    DynamicLiChaoTree<long long> lct(-1000000000, 1000000001);
    lct.reserve(n + q + 1);
    for (int i = 0; i < n; i++) {
        long long a, b;
        fin >> a >> b;
        lct.add_line(a, b);
    }
    while (q--) {
        int t;
        fin >> t;
        if (t == 0) {
            long long a, b;
            fin >> a >> b;
            lct.add_line(a, b);
        } else {
            long long p;
            fin >> p;
            fout << lct.get(p) << '\n';
        }
    }
    return 0;
}
