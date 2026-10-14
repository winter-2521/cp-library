#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../math/modint.hpp"
#include "../../data_structure/foldable_queue.hpp"
#include "../../data_structure/foldable_deque.hpp"

// FoldableQueue / FoldableDeque を愚直と照合する (非可換な 1 次関数の合成で確認)

using mint = ModInt998244353;
using F = Affine<mint>;
using MA = MonoidAffine<mint>;

F rand_f(mt19937_64 &rng) { return F(rng() % 5 + 1, rng() % 5); }
F brute(const deque<F> &a) {
    F res;
    for (auto &f : a) res = res.then(f);
    return res;
}

int main() {
    mt19937_64 rng(3);
    for (int it = 0; it < 20; it++) {
        FoldableQueue<MA> que;
        FoldableDeque<MA> deq;
        deque<F> rq, rd;
        for (int step = 0; step < 3000; step++) {
            int t = rng() % 3;
            if (t == 0 || rq.empty()) {
                F f = rand_f(rng);
                que.push(f), rq.push_back(f);
            } else if (t == 1) {
                assert(que.front() == rq.front());
                que.pop(), rq.pop_front();
            }
            assert(que.size() == (int)rq.size() && que.empty() == rq.empty());
            assert(que.all_prod() == brute(rq));

            t = rng() % 5;
            if (t <= 1 || rd.empty()) {
                F f = rand_f(rng);
                if (rng() % 2) deq.push_front(f), rd.push_front(f);
                else deq.push_back(f), rd.push_back(f);
            } else if (t == 2) {
                assert(deq.front() == rd.front());
                deq.pop_front(), rd.pop_front();
            } else if (t == 3) {
                assert(deq.back() == rd.back());
                deq.pop_back(), rd.pop_back();
            }
            assert(deq.size() == (int)rd.size() && deq.empty() == rd.empty());
            if (!rd.empty()) assert(deq.front() == rd.front() && deq.back() == rd.back());
            assert(deq.all_prod() == brute(rd));
        }
    }
    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
