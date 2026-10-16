#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum"
#include "../io/fastio.hpp"
#include "../graph/offline_dynamic_connectivity.hpp"

int main() {
    int n, q;
    fin >> n >> q;
    vector<long long> a(n);
    fin >> a;
    OfflineDynamicConnectivity dc(n, a);
    while (q--) {
        int t;
        fin >> t;
        if (t == 0) {
            int u, v;
            fin >> u >> v;
            dc.link(u, v);
        } else if (t == 1) {
            int u, v;
            fin >> u >> v;
            dc.cut(u, v);
        } else if (t == 2) {
            int v;
            long long x;
            fin >> v >> x;
            dc.add(v, x);
        } else {
            int v;
            fin >> v;
            dc.query(v);
        }
    }
    for (auto x : dc.solve()) fout << x << '\n';
    return 0;
}
