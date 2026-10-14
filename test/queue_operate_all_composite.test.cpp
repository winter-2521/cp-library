#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include "../io/fastio.hpp"
#include "../math/modint.hpp"
#include "../data_structure/foldable_queue.hpp"

using mint = ModInt998244353;

int main() {
    int q;
    fin >> q;
    FoldableQueue<MonoidAffine<mint>> que;
    que.reserve(q);
    while (q--) {
        int t;
        fin >> t;
        if (t == 0) {
            mint a, b;
            fin >> a >> b;
            que.push({a, b});
        } else if (t == 1) {
            que.pop();
        } else {
            mint x;
            fin >> x;
            fout << que.all_prod()(x) << '\n';
        }
    }
    return 0;
}
