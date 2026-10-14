#pragma once
#include "../template.hpp"

// 静的な重み付き点の長方形和 (Rectangle Sum)．オンライン
// 点を x でソートし，y (座標圧縮) の列を重み付きウェーブレット行列で持つ．構築 O(n log n)，クエリ O(log n)
// X: 座標の型，W: 重みの型
template <class X, class W>
struct StaticRectangleSum {
    // 64 bit ごとに，ビット列とそれより前の 1 の個数をまとめて持つ
    struct BitVector {
        struct Block {
            uint64_t bits;
            int cnt;
        };
        vector<Block> b;
        void init(int n) { b.assign((n >> 6) + 1, {0, 0}); }
        void set(int i) { b[i >> 6].bits |= 1ULL << (i & 63); }
        void build() {
            for (size_t i = 1; i < b.size(); i++) b[i].cnt = b[i - 1].cnt + __builtin_popcountll(b[i - 1].bits);
        }
        int rank1(int i) const {
            const Block &x = b[i >> 6];
            return x.cnt + __builtin_popcountll(x.bits & ((1ULL << (i & 63)) - 1));
        }
    };

    int n, lg;
    vector<X> xs, ys;           // xs: 点の x (昇順)，ys: y の種類 (昇順)
    vector<BitVector> bv;
    vector<int> zeros;
    vector<vector<W>> sum;      // sum[h][i]: 段 h で振り分けた後の列の先頭 i 個の重みの和

    StaticRectangleSum() : n(0), lg(0) {}
    StaticRectangleSum(const vector<X> &x, const vector<X> &y, const vector<W> &w) : n(x.size()) {
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j) { return x[i] < x[j]; });
        xs.resize(n);
        for (int k = 0; k < n; k++) xs[k] = x[ord[k]];
        ys = y;
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        vector<int> cur(n), nxt(n);
        vector<W> cw(n), nw(n);
        for (int k = 0; k < n; k++) {
            cur[k] = lower_bound(ys.begin(), ys.end(), y[ord[k]]) - ys.begin();
            cw[k] = w[ord[k]];
        }
        lg = 1;
        while ((1 << lg) < (int)ys.size()) lg++;
        bv.resize(lg), zeros.resize(lg), sum.assign(lg, vector<W>(n + 1, W(0)));
        for (int h = lg - 1; h >= 0; h--) {
            bv[h].init(n);
            int z = 0;
            for (int i = 0; i < n; i++) {
                if (cur[i] >> h & 1) bv[h].set(i);
                else z++;
            }
            bv[h].build();
            zeros[h] = z;
            int p0 = 0, p1 = z;
            for (int i = 0; i < n; i++) {
                int p = (cur[i] >> h & 1) ? p1++ : p0++;
                nxt[p] = cur[i], nw[p] = cw[i];
            }
            swap(cur, nxt), swap(cw, nw);
            for (int i = 0; i < n; i++) sum[h][i + 1] = sum[h][i] + cw[i];
        }
    }

    int size() const { return n; }

    // l <= x < r, d <= y < u の点の重みの和
    W sum_rect(X l, X d, X r, X u) const {
        int il = lower_idx(xs, l), ir = lower_idx(xs, r);
        int yd = lower_idx(ys, d), yu = lower_idx(ys, u);
        if (il >= ir || yd >= yu) return W(0);
        if (yu >= (1 << lg)) return total(il, ir) - prefix(il, ir, yd);
        // 上の段で yd と yu のビットが同じ間は 2 つの和の差に効かないので，共通に降りる
        int h = lg - 1;
        for (; h >= 0 && ((yd ^ yu) >> h & 1) == 0; h--) {
            int l1 = bv[h].rank1(il), r1 = bv[h].rank1(ir);
            if (yu >> h & 1) il = zeros[h] + l1, ir = zeros[h] + r1;
            else il -= l1, ir -= r1;
        }
        // ビット h で yd は 0，yu は 1
        int l1 = bv[h].rank1(il), r1 = bv[h].rank1(ir);
        int l0 = il - l1, r0 = ir - r1;
        return (sum[h][r0] - sum[h][l0]) + prefix_from(zeros[h] + l1, zeros[h] + r1, yu, h - 1) - prefix_from(l0, r0, yd, h - 1);
    }
    W operator()(X l, X d, X r, X u) const { return sum_rect(l, d, r, u); }

  private:
    // 分岐の少ない lower_bound (添字を返す)
    static int lower_idx(const vector<X> &v, const X &x) {
        int n = v.size();
        if (n == 0) return 0;
        const X *base = v.data();
        while (n > 1) {
            int half = n >> 1;
            base = base[half - 1] < x ? base + half : base;
            n -= half;
        }
        return int(base - v.data()) + (*base < x);
    }

    // x の順で [l, r) 番目の点のうち y の番号が v 未満のものの重みの和
    W prefix(int l, int r, int v) const {
        if (v >= (1 << lg)) return total(l, r);
        return prefix_from(l, r, v, lg - 1);
    }
    // 段 h から下だけを見る版 (段 h での区間が [l, r))
    W prefix_from(int l, int r, int v, int h0) const {
        W res(0);
        for (int h = h0; h >= 0; h--) {
            int l1 = bv[h].rank1(l), r1 = bv[h].rank1(r);
            int l0 = l - l1, r0 = r - r1;
            if (v >> h & 1) {
                res += sum[h][r0] - sum[h][l0];
                l = zeros[h] + l1, r = zeros[h] + r1;
            } else {
                l = l0, r = r0;
            }
        }
        return res;
    }
    W total(int l, int r) const {
        // 最上段で振り分ける前の [l, r) の和 = 0 側と 1 側の和
        int h = lg - 1;
        int l1 = bv[h].rank1(l), r1 = bv[h].rank1(r);
        return (sum[h][r - r1] - sum[h][l - l1]) + (sum[h][zeros[h] + r1] - sum[h][zeros[h] + l1]);
    }
};

// 点の追加ができる長方形和 (Point Add Rectangle Sum)．オンライン
// 大きさが 2 冪の StaticRectangleSum を高々 log 個持ち，追加のたびに同じ大きさのものを併合して作り直す (二進カウンタ)
// 追加ならし O(log^2 n)，クエリ O(log^2 n)
template <class X, class W>
struct DynamicRectangleSum {
    struct Bucket {
        vector<X> x, y;
        vector<W> w;
        StaticRectangleSum<X, W> rs;
    };
    vector<Bucket> buckets;

    DynamicRectangleSum() = default;
    // 初期の点をまとめて入れる
    DynamicRectangleSum(const vector<X> &x, const vector<X> &y, const vector<W> &w) {
        if (!x.empty()) buckets.push_back({x, y, w, StaticRectangleSum<X, W>(x, y, w)});
    }

    // 点 (x, y) に重み w の点を追加
    void add(X x, X y, W w) {
        Bucket b{{x}, {y}, {w}, {}};
        while (!buckets.empty() && buckets.back().x.size() <= b.x.size()) {
            Bucket &t = buckets.back();
            b.x.insert(b.x.end(), t.x.begin(), t.x.end());
            b.y.insert(b.y.end(), t.y.begin(), t.y.end());
            b.w.insert(b.w.end(), t.w.begin(), t.w.end());
            buckets.pop_back();
        }
        b.rs = StaticRectangleSum<X, W>(b.x, b.y, b.w);
        buckets.push_back(std::move(b));
    }

    // l <= x < r, d <= y < u の点の重みの和
    W sum_rect(X l, X d, X r, X u) const {
        W res(0);
        for (auto &b : buckets) res += b.rs.sum_rect(l, d, r, u);
        return res;
    }
    W operator()(X l, X d, X r, X u) const { return sum_rect(l, d, r, u); }
};
