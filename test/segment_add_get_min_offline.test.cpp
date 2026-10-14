#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"
#include "../io/fastio.hpp"
#include "../data_structure/li_chao_tree.hpp"

// 座標を先読みする版 (LiChaoTree)
int main() {
    int n, q;
    fin >> n >> q;
    vector<array<long long, 4>> seg(n);
    for (auto &[l, r, a, b] : seg) fin >> l >> r >> a >> b;
    vector<array<long long, 5>> qs(q);
    vector<long long> xs;
    for (auto &x : qs) {
        fin >> x[0];
        if (x[0] == 0) fin >> x[1] >> x[2] >> x[3] >> x[4];
        else fin >> x[1], xs.push_back(x[1]);
    }
    LiChaoTree<long long> lct(xs);
    for (auto &[l, r, a, b] : seg) lct.add_segment(l, r, a, b);
    for (auto &x : qs) {
        if (x[0] == 0) {
            lct.add_segment(x[1], x[2], x[3], x[4]);
        } else {
            long long y = lct.get(x[1]);
            if (y == numeric_limits<long long>::max()) fout << "INFINITY\n";
            else fout << y << '\n';
        }
    }
    return 0;
}
