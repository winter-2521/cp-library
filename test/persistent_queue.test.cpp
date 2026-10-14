#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"
#include "../io/fastio.hpp"
#include "../data_structure/persistent_queue.hpp"

int main() {
    int q;
    fin >> q;
    PersistentQueue<int> pq;
    pq.reserve(q);
    vector<int> ver(q + 1);  // ver[i + 1] = S_i の版 (ver[0] = S_{-1})
    ver[0] = pq.empty_version();
    for (int i = 0; i < q; i++) {
        int t, k;
        fin >> t >> k;
        if (t == 0) {
            int x;
            fin >> x;
            ver[i + 1] = pq.push(ver[k + 1], x);
        } else {
            fout << pq.front(ver[k + 1]) << '\n';
            ver[i + 1] = pq.pop(ver[k + 1]);
        }
    }
    return 0;
}
