#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"
#include "../io/fastio.hpp"
#include "../data_structure/interval_heap.hpp"

int main() {
    int n, q;
    fin >> n >> q;
    vector<int> s(n);
    fin >> s;
    IntervalHeap<int> hp;
    hp.reserve(n + q);
    for (int v : s) hp.push(v);
    while (q--) {
        int t;
        fin >> t;
        if (t == 0) {
            int x;
            fin >> x;
            hp.push(x);
        } else if (t == 1) {
            fout << hp.pop_min() << '\n';
        } else {
            fout << hp.pop_max() << '\n';
        }
    }
    return 0;
}
