#pragma once
#include "../template.hpp"

struct UnionFind {
    //親を保存する配列
    vector<int> par;

    UnionFind(int n=0): par(n,-1) {}

    //集合の代表元を返す
    int find(int x) {
        if(par[x] < 0) return x;
        return par[x] = find(par[x]);
    }

    //x を含む集合と y を含む集合をマージ
    //既に同じ集合に属すならtrue , それ以外でfalseを返す．
    bool unite(int x, int y){
        x = find(x); y = find(y);
        if(x==y) return false;
        if(par[x] > par[y]) swap(x,y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    //x と y が同じ集合に属すならtrue , それ以外でfalseを返す．
    bool same(int x, int y) {return find(x) == find(y);}

    //x の属する集合のサイズを返す．
    int size(int x) {return -par[find(x)];}

    //現在存在する集合の列挙
    vector<vector<int>> groups(){
        vector<vector<int>> res(par.size());
        for(int i = 0; i < (int)par.size(); i++){
            res[find(i)].push_back(i);
        }
        res.erase(remove_if(res.begin(), res.end(),
                [&](const vector<int> &v) { return v.empty(); }),
                res.end());
        return res;
    }
};