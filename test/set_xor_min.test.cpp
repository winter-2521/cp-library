#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"
#include "../io/fastio.hpp"
#include "../data_structure/binary_trie.hpp"

int main() {
    int q;
    fin >> q;
    BinaryTrie<30> trie;
    trie.reserve(q * 30 + 1);
    while (q--) {
        int t;
        unsigned x;
        fin >> t >> x;
        if (t == 0) trie.insert_unique(x);
        else if (t == 1) trie.erase_one(x);
        else fout << trie.xor_min(x) << '\n';
    }
    return 0;
}
