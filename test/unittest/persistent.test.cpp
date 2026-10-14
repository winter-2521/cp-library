#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../data_structure/persistent_queue.hpp"
#include "../../data_structure/persistent_array.hpp"
#include "../../data_structure/persistent_unionfind.hpp"

// PersistentQueue / PersistentArray / PersistentUnionFind を，版ごとに全体を複製する愚直と照合する

int main() {
    mt19937_64 rng(29);
    // PersistentQueue
    {
        PersistentQueue<int> pq;
        vector<int> ver{pq.empty_version()};
        vector<deque<int>> ref{{}};
        for (int step = 0; step < 3000; step++) {
            int k = rng() % ver.size();
            if (ref[k].empty() || rng() % 2) {
                int x = rng() % 1000;
                ver.push_back(pq.push(ver[k], x));
                auto d = ref[k];
                d.push_back(x);
                ref.push_back(d);
            } else {
                assert(pq.front(ver[k]) == ref[k].front());
                ver.push_back(pq.pop(ver[k]));
                auto d = ref[k];
                d.pop_front();
                ref.push_back(d);
            }
            int t = ver.size() - 1;
            assert(pq.size(ver[t]) == (int)ref[t].size() && pq.empty(ver[t]) == ref[t].empty());
        }
    }
    // 長い鎖 (祖先の跳び先を深く使う)
    {
        PersistentQueue<int> pq;
        int v = pq.empty_version();
        for (int i = 0; i < 5000; i++) v = pq.push(v, i);
        int w = v;
        for (int i = 0; i < 5000; i++) {
            assert(pq.front(w) == i && pq.size(w) == 5000 - i);
            w = pq.pop(w);
        }
        assert(pq.empty(w) && pq.front(v) == 0);
    }
    // PersistentArray
    for (int n : {1, 2, 7, 8, 9, 64, 100}) {
        vector<int> a(n);
        for (auto &x : a) x = rng() % 100;
        PersistentArray<int> pa(a);
        PersistentArray<int, 1> pb(a);
        vector<int> va{0}, vb{0};
        vector<vector<int>> ref{a};
        for (int step = 0; step < 2000; step++) {
            int k = rng() % ref.size(), i = rng() % n, x = rng() % 100;
            assert(pa.get(va[k], i) == ref[k][i] && pb.get(vb[k], i) == ref[k][i]);
            va.push_back(pa.set(va[k], i, x)), vb.push_back(pb.set(vb[k], i, x));
            auto c = ref[k];
            c[i] = x;
            ref.push_back(c);
        }
    }
    // PersistentUnionFind
    for (int n : {1, 2, 5, 30}) {
        PersistentUnionFind uf(n);
        vector<int> ver{uf.initial_version()};
        vector<vector<int>> comp{vector<int>(n)};
        iota(comp[0].begin(), comp[0].end(), 0);
        for (int step = 0; step < 2000; step++) {
            int k = rng() % ver.size(), x = rng() % n, y = rng() % n;
            assert(uf.same(ver[k], x, y) == (comp[k][x] == comp[k][y]));
            assert(uf.size(ver[k], x) == count(comp[k].begin(), comp[k].end(), comp[k][x]));
            ver.push_back(uf.merge(ver[k], x, y));
            auto c = comp[k];
            int cx = c[x], cy = c[y];
            for (auto &z : c) if (z == cy) z = cx;
            comp.push_back(c);
        }
    }
    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
