#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"
#include "../io/fastio.hpp"
#include "../tree/hld.hpp"

int main() {
    int n, q;
    fin >> n >> q;
    vector<pair<int, int>> edges(n - 1);
    for (auto &[a, b] : edges) fin >> a >> b;
    HLD hld(n, edges);
    while (q--) {
        int s, t, i;
        fin >> s >> t >> i;
        fout << hld.jump(s, t, i) << '\n';
    }
    return 0;
}
