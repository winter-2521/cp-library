#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"
#include "../data_structure/weighted_dsu.hpp"

//verify for UnionFind

int main(){
    int n,q; cin >> n >> q;
    WeightedUnionFind<int> dsu(n);
    for(int i = 0;i < q;i++){
        int query_type; cin >> query_type;
        if(query_type == 0){
            int x,y,z; cin >> x >> y >> z;
            dsu.unite(y,x,z);
        }
        if(query_type == 1){
            int x,y; cin >> x >> y;
            if(dsu.same(x,y)){
                cout << dsu.diff(y,x);
            }else{
                cout << "?\n";
            }
        }
    }
    return 0;
}