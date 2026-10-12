#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../math/modint.hpp"
#include "../../data_structure/potentialized_unionfind.hpp"
#include <atcoder/modint>

// 自作 ModInt を ACL の static_modint と照合する．あわせて ACL の modint が他のライブラリでそのまま使えることを確認する

template <uint32_t MOD>
void check(mt19937_64 &rng) {
    using A = atcoder::static_modint<MOD>;
    using M = ModInt<MOD>;
    static_assert(M::mod() == A::mod());
    for (int it = 0; it < 200000; it++) {
        long long x = (long long)rng(), y = (long long)rng();
        if (it % 3 == 0) x %= 1000, y %= 1000;
        M a(x), b(y);
        A c(x), d(y);
        assert(a.val() == c.val() && b.val() == d.val());
        assert((a + b).val() == (c + d).val());
        assert((a - b).val() == (c - d).val());
        assert((a * b).val() == (c * d).val());
        assert((-a).val() == (-c).val());
        unsigned long long ux = rng();
        assert(M(ux).val() == A(ux).val());
        long long e = rng() % 1000000;
        assert(a.pow(e).val() == c.pow(e).val());
        if (gcd((long long)b.val(), (long long)MOD) == 1) {
            assert((a / b).val() == (c / d).val());
            assert(b.inv().val() == d.inv().val());
            assert((b.pow(-e) * b.pow(e)).val() == 1 % MOD);
        }
        M p = a;
        A q = c;
        assert((p++).val() == (q++).val() && p.val() == q.val());
        assert((--p).val() == (--q).val());
    }
}

int main() {
    mt19937_64 rng(1);
    check<998244353>(rng);
    check<1000000007>(rng);
    check<2>(rng);
    check<12>(rng);
    check<1>(rng);
    check<2147483647>(rng);

    // ACL の modint でポテンシャル付き Union-Find が動く
    using am = atcoder::modint998244353;
    PotentializedUnionFind<AdditiveGroup<am>> uf(3);
    assert(uf.merge(0, 1, am(5)));
    assert(uf.merge(1, 2, am(-2)));
    assert(uf.diff(0, 2).val() == 3);
    assert(!uf.merge(2, 0, am(4)));
    assert(uf.merge(2, 0, am(-3)));

    // fastio が ACL の modint と自作 ModInt の両方を読み書きできる (出力は aplusb の答え)
    // 入力は 1e9 以下なので，法 1e9+7 で読めば値は変わらない
    static_assert(fastio::has_val<am>::value && fastio::has_val<ModInt998244353>::value);
    atcoder::modint1000000007 a;
    ModInt1000000007 b;
    fin >> a >> b;
    fout << (long long)a.val() + b.val() << '\n';
    return 0;
}
