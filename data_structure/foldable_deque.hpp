#pragma once
#include "../template.hpp"
#include "../algebra/monoid.hpp"

// https://github.com/winter-2521/cp-library

// 全体の積が取れる両端キュー
// M はモノイド (非可換でもよい)．積は「先頭から末尾の順」= op(front, ..., back)
// 先頭側・末尾側の 2 本のスタックに累積積を積む．片方が空のときに取り出すと，もう片方を半分に分けて作り直す (ならし O(1))
template <class M>
struct FoldableDeque {
    using S = typename M::S;
    // fv.back() が先頭．fp[i] = op(fv[i], fv[i-1], ..., fv[0])
    // bv.back() が末尾．bp[i] = op(bv[0], ..., bv[i])
    vector<S> fv, fp, bv, bp;

    FoldableDeque() = default;

    int size() const { return fv.size() + bv.size(); }
    bool empty() const { return fv.empty() && bv.empty(); }
    void reserve(int n) { fv.reserve(n), fp.reserve(n), bv.reserve(n), bp.reserve(n); }
    void clear() { fv.clear(), fp.clear(), bv.clear(), bp.clear(); }

    void push_front(const S &x) {
        fp.push_back(fv.empty() ? x : M::op(x, fp.back()));
        fv.push_back(x);
    }
    void push_back(const S &x) {
        bp.push_back(bv.empty() ? x : M::op(bp.back(), x));
        bv.push_back(x);
    }

    // 先頭を削除 (空でないこと)
    void pop_front() {
        if (fv.empty()) rebalance(true);
        fv.pop_back(), fp.pop_back();
    }
    // 末尾を削除 (空でないこと)
    void pop_back() {
        if (bv.empty()) rebalance(false);
        bv.pop_back(), bp.pop_back();
    }

    // 先頭 / 末尾 (空でないこと)
    S front() const { return fv.empty() ? bv.front() : fv.back(); }
    S back() const { return bv.empty() ? fv.front() : bv.back(); }

    // op(先頭, ..., 末尾)．空なら e()
    S all_prod() const {
        if (fv.empty()) return bv.empty() ? M::e() : bp.back();
        if (bv.empty()) return fp.back();
        return M::op(fp.back(), bp.back());
    }

  private:
    // to_front: 先頭側が空になったので末尾側から分ける (逆も同様)
    void rebalance(bool to_front) {
        // 全要素を先頭から末尾の順に並べる
        vector<S> all;
        all.reserve(fv.size() + bv.size());
        for (int i = (int)fv.size() - 1; i >= 0; i--) all.push_back(fv[i]);
        for (auto &x : bv) all.push_back(x);
        int m = all.size();
        // 取り出す側に少なくとも 1 個入るように分ける
        int k = to_front ? (m + 1) / 2 : m / 2;  // 先頭側に入れる個数
        clear();
        for (int i = k - 1; i >= 0; i--) push_front(all[i]);
        for (int i = k; i < m; i++) push_back(all[i]);
    }
};
