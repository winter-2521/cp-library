#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
#include "../io/fastio.hpp"
#include "../data_structure/fast_set.hpp"

int main() {
    int n, q;
    string t;
    fin >> n >> q >> t;
    FastSet fs(n, [&](int i) { return t[i] == '1'; });
    while (q--) {
        int c, k;
        fin >> c >> k;
        if (c == 0) fs.insert(k);
        else if (c == 1) fs.erase(k);
        else if (c == 2) fout << fs.contains(k) << '\n';
        else if (c == 3) fout << fs.next(k) << '\n';
        else fout << fs.prev(k) << '\n';
    }
    return 0;
}
