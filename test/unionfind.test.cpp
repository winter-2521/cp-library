#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/4/ITP1_4_A"
#include "../template.hpp"
#include "../graph/dsu.hpp"

//verify for UnionFind

int main(){
    int n,q; cin >> n >> q;
    UnionFind dsu(n);
    for(int query = 0; query < q; query++){
        int t,u,v; cin >> t >> u >> v;
        if(t == 0){//test for unite
            dsu.unite(u,v);
        }
        if(t == 1){//test for same?
            cout << dsu.same(u,v) << '\n';
        }
    }
    return 0;
}