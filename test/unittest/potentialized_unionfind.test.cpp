#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../data_structure/potentialized_unionfind.hpp"

// 隠れた値を決めておき，正しい関係・誤った関係をランダムに与えて愚直と照合する

// 4 要素の置換のなす群 (非可換)．p * q は「先に q，次に p」ではなく配列としての合成 (p * q)[i] = p[q[i]]
struct S4 {
    using T = array<int, 4>;
    static T op(const T &p, const T &q) { return {p[q[0]], p[q[1]], p[q[2]], p[q[3]]}; }
    static T inv(const T &p) {
        T r;
        for (int i = 0; i < 4; i++) r[p[i]] = i;
        return r;
    }
    static T e() { return {0, 1, 2, 3}; }
};

template <class G, class Gen>
void check(mt19937_64 &rng, int n, Gen gen) {
    using T = typename G::T;
    vector<T> hidden(n);
    for (auto &x : hidden) x = gen();
    PotentializedUnionFind<G> uf(n);
    vector<int> comp(n);
    iota(comp.begin(), comp.end(), 0);
    for (int it = 0; it < 3000; it++) {
        int x = rng() % n, y = rng() % n;
        T truth = G::op(G::inv(hidden[x]), hidden[y]);
        if (rng() % 2) {
            assert(uf.merge(x, y, truth));
            int cx = comp[x], cy = comp[y];
            for (auto &c : comp) if (c == cy) c = cx;
        } else {
            T w = gen();
            bool ok = uf.merge(x, y, w);
            if (comp[x] == comp[y]) {
                assert(ok == (w == truth));
            } else {
                // 別の集合同士は必ず併合できる．隠れた値を新しい関係に合わせて書き換える
                assert(ok);
                int cx = comp[x], cy = comp[y];
                // y の集合全体に左から hidden[x] w hidden[y]^{-1} を掛けると a_x^{-1} a_y = w になる
                T m = G::op(G::op(hidden[x], w), G::inv(hidden[y]));
                for (int i = 0; i < n; i++) if (comp[i] == cy) hidden[i] = G::op(m, hidden[i]), comp[i] = cx;
            }
        }
        int u = rng() % n, v = rng() % n;
        assert(uf.same(u, v) == (comp[u] == comp[v]));
        if (comp[u] == comp[v]) assert(uf.diff(u, v) == G::op(G::inv(hidden[u]), hidden[v]));
        assert(uf.size(u) == count(comp.begin(), comp.end(), comp[u]));
    }
    auto gs = uf.groups();
    int total = 0;
    for (auto &g : gs) {
        total += g.size();
        for (int v : g) assert(comp[v] == comp[g[0]]);
    }
    assert(total == n);
}

int main() {
    mt19937_64 rng(8);
    for (int n : {1, 2, 5, 30}) {
        check<AdditiveGroup<long long>>(rng, n, [&] { return (long long)(rng() % 7) - 3; });
        check<XorGroup<int>>(rng, n, [&] { return int(rng() % 4); });
        check<S4>(rng, n, [&] {
            S4::T p = S4::e();
            shuffle(p.begin(), p.end(), rng);
            return p;
        });
    }
    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
