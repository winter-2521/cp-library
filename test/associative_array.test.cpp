#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include "../io/fastio.hpp"
#include "../data_structure/hash_map.hpp"

int main() {
    int q;
    fin >> q;
    HashMap<unsigned long long, unsigned long long> mp;
    while (q--) {
        int t;
        unsigned long long k;
        fin >> t >> k;
        if (t == 0) {
            unsigned long long v;
            fin >> v;
            mp[k] = v;
        } else {
            fout << mp.get(k, 0) << '\n';
        }
    }
    return 0;
}
