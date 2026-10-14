#define PROBLEM "https://judge.yosupo.jp/problem/deque_operate_all_composite"
#include "../io/fastio.hpp"
#include "../math/modint.hpp"
#include "../data_structure/foldable_deque.hpp"

using mint = ModInt998244353;

int main() {
    int q;
    fin >> q;
    FoldableDeque<MonoidAffine<mint>> deq;
    deq.reserve(q);
    while (q--) {
        int t;
        fin >> t;
        if (t == 0 || t == 1) {
            mint a, b;
            fin >> a >> b;
            if (t == 0) deq.push_front({a, b});
            else deq.push_back({a, b});
        } else if (t == 2) {
            deq.pop_front();
        } else if (t == 3) {
            deq.pop_back();
        } else {
            mint x;
            fin >> x;
            fout << deq.all_prod()(x) << '\n';
        }
    }
    return 0;
}
