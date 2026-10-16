#define PROBLEM "https://judge.yosupo.jp/problem/st_numbering"
#include "../io/fastio.hpp"
#include "../graph/st_numbering.hpp"

int main() {
    int T;
    fin >> T;
    while (T--) {
        int n, m, s, t;
        fin >> n >> m >> s >> t;
        vector<pair<int, int>> edges(m);
        for (auto &[a, b] : edges) fin >> a >> b;
        auto p = st_numbering(n, edges, s, t);
        if (p.empty()) fout << "No\n";
        else fout << "Yes\n" << p << '\n';
    }
    return 0;
}
