#define PROBLEM "https://judge.yosupo.jp/problem/ordered_set"
#include "../io/fastio.hpp"
#include "../data_structure/ordered_set.hpp"

int main() {
    int n, q;
    fin >> n >> q;
    vector<int> a(n);
    fin >> a;
    OrderedSet<int> st(a);
    while (q--) {
        int t, x;
        fin >> t >> x;
        if (t == 0) st.insert(x);
        else if (t == 1) st.erase(x);
        else if (t == 2) fout << st.kth(x - 1) << '\n';
        else if (t == 3) fout << st.count_le(x) << '\n';
        else if (t == 4) fout << st.max_le(x) << '\n';
        else fout << st.min_ge(x) << '\n';
    }
    return 0;
}
