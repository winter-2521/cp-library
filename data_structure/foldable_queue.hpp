#pragma once
#include "../template.hpp"
#include "../algebra/monoid.hpp"

// https://github.com/winter-2521/cp-library

// 全体の積が取れるキュー (Sliding Window Aggregation)
// M はモノイド (非可換でもよい)．積は「先頭から末尾の順」= op(front, ..., back)
// 2 本のスタックで持つ．front 側は「その要素から front 側の底までの積」を積んでおく
template <class M>
struct FoldableQueue {
    using S = typename M::S;
    vector<S> front_val, front_prod;  // front_val.back() が先頭．front_prod[i] = op(front_val[i], ..., front_val[0])
    vector<S> back_val;               // 末尾側 (push 順)
    S back_prod = M::e();             // back_val 全体の積

    FoldableQueue() = default;

    int size() const { return front_val.size() + back_val.size(); }
    bool empty() const { return front_val.empty() && back_val.empty(); }
    void reserve(int n) { front_val.reserve(n), front_prod.reserve(n), back_val.reserve(n); }
    void clear() { front_val.clear(), front_prod.clear(), back_val.clear(), back_prod = M::e(); }

    // 末尾に x を追加
    void push(const S &x) {
        back_val.push_back(x);
        back_prod = M::op(back_prod, x);
    }

    // 先頭を削除 (空でないこと)
    void pop() {
        if (front_val.empty()) move_back_to_front();
        front_val.pop_back();
        front_prod.pop_back();
    }

    // 先頭 (空でないこと)
    S front() {
        if (front_val.empty()) move_back_to_front();
        return front_val.back();
    }

    // op(先頭, ..., 末尾)．空なら e()
    S all_prod() const {
        if (front_prod.empty()) return back_prod;
        return M::op(front_prod.back(), back_prod);
    }

  private:
    void move_back_to_front() {
        S acc = M::e();
        for (int i = (int)back_val.size() - 1; i >= 0; i--) {
            acc = M::op(back_val[i], acc);
            front_val.push_back(back_val[i]);
            front_prod.push_back(acc);
        }
        back_val.clear();
        back_prod = M::e();
    }
};
