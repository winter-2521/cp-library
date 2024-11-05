#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "../graph/dijkstra.hpp"

//verify for Dijkstra

int main(){
    int n,m,s,t; cin >> n >> m >> s >> t;
    Graph<long long> g(n);
    for(int idx = 0; idx < m; idx++)
    {
        int a,b; long long c; cin >> a >> b >> c;
        g.add_directed_edge(a,b,c);
    }
    
    auto [dist,prev,path] = Dijikstra(g,s,t);

    if(dist[t] == -1) {
        cout << "-1\n";
        return 0;
    }
    cout << dist[t] << " " << path.size()-1 << "\n";
    rep(idx,path.size()-1){
        cout << path[idx] << " " << path[idx+1] << "\n";
    }

    return 0;
}