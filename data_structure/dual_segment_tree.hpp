#pragma once
#include "../template.hpp"
#include "../algebra/monoid.hpp"

// https://github.com/winter-2521/cp-library

// 双対セグメント木 (区間作用・一点取得)
// 各位置 i に作用 F_i (はじめ e()) を持ち，区間 [l, r) の各 F_i を op(F_i, f) に更新する．
// M はモノイドで，op(x, y) は「先に x，次に y」という時系列順の合成 (非可換でもよい)
// 例: DualSegmentTree<MonoidAffine<mint>> で区間 1 次関数作用，get(i)(a[i]) で現在の値
template <class M>
struct DualSegmentTree {
    using S = typename M::S;
    int n, sz, lg;
    vector<S> lz;

    DualSegmentTree(int n = 0) : n(n) {
        lg = 0;
        while ((1 << lg) < n) lg++;
        sz = 1 << lg;
        lz.assign(2 * sz, M::e());
    }

    int size() const { return n; }

    // i in [l, r) について F_i = op(F_i, f)
    void apply(int l, int r, const S &f) {
        if (l >= r) return;
        l += sz, r += sz;
        // 非可換なので，先に境界の祖先の作用を下ろしておく
        for (int i = lg; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
        while (l < r) {
            if (l & 1) lz[l] = M::op(lz[l], f), l++;
            if (r & 1) --r, lz[r] = M::op(lz[r], f);
            l >>= 1, r >>= 1;
        }
    }

    // F_p = op(F_p, f)
    void apply(int p, const S &f) { apply(p, p + 1, f); }

    // F_p (位置 p にこれまでに作用した全てを時系列順に合成したもの)
    S get(int p) const {
        p += sz;
        S res = lz[p];
        // 祖先の作用の方が新しい
        for (p >>= 1; p; p >>= 1) res = M::op(res, lz[p]);
        return res;
    }
    S operator[](int p) const { return get(p); }

    // F_p = f に置き換える
    void set(int p, const S &f) {
        p += sz;
        for (int i = lg; i >= 1; i--) push(p >> i);
        lz[p] = f;
    }

  private:
    void push(int k) {
        lz[2 * k] = M::op(lz[2 * k], lz[k]);
        lz[2 * k + 1] = M::op(lz[2 * k + 1], lz[k]);
        lz[k] = M::e();
    }
};
