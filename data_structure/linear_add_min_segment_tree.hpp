#pragma once
#include "../template.hpp"

// 区間に 1 次関数 (b i + c) を足す・区間最小値 (Range Linear Add Range Min)
// 点 (i, a_i) の下側凸包を，各ノードに「左の子の凸包と右の子の凸包をつなぐ橋 (bridge)」だけ持つ形で表す．
// 1 次関数を足しても凸包の形 (どの点が頂点か・橋) は変わらないので，遅延で足せる．
// 最小値は橋の傾きの符号を見て根から降りれば求まる．橋の再計算は左右の子を同時に降りて O(log n)
// MAX = true なら区間最大値．T は符号付き整数
template <class T = long long, bool MAX = false>
struct LinearAddMinSegmentTree {
    using W = __int128;
    struct Node {
        int lx, rx;    // 橋の端点の添字 (葉なら lx = rx = その位置)
        T ly, ry;      // 橋の端点の値 (このノードの遅延まで反映済み)
        T lb, lc;      // 子に伝えていない遅延 (b i + c を足す)
    };
    int n;
    vector<Node> d;

    LinearAddMinSegmentTree(const vector<T> &a) : n(a.size()), d(4 * std::max<int>(1, a.size())) {
        if (n) build(1, 0, n, a);
    }

    int size() const { return n; }

    // i in [l, r) について a[i] += b * i + c
    void add(int l, int r, T b, T c) {
        if (MAX) b = -b, c = -c;
        if (l < r) add(1, 0, n, l, r, b, c);
    }

    // min(a[l], ..., a[r-1]) (MAX なら max)．l < r であること
    T min(int l, int r) {
        T res = query(1, 0, n, l, r);
        return MAX ? -res : res;
    }
    T max(int l, int r) { return min(l, r); }
    T all_min() { return MAX ? -node_min(1, 0, n) : node_min(1, 0, n); }

    T get(int i) {
        int k = 1, l = 0, r = n;
        while (r - l > 1) {
            push(k);
            int m = (l + r) >> 1;
            if (i < m) k = 2 * k, r = m;
            else k = 2 * k + 1, l = m;
        }
        return MAX ? -d[k].ly : d[k].ly;
    }

    void set(int i, T x) { set(1, 0, n, i, MAX ? -x : x); }

  private:
    struct P {
        int x;
        T y;
    };

    void build(int k, int l, int r, const vector<T> &a) {
        d[k].lb = d[k].lc = 0;
        if (r - l == 1) {
            T v = MAX ? -a[l] : a[l];
            d[k].lx = d[k].rx = l, d[k].ly = d[k].ry = v;
            return;
        }
        int m = (l + r) >> 1;
        build(2 * k, l, m, a), build(2 * k + 1, m, r, a);
        pull(k, l, m, r);
    }

    void apply(int k, T b, T c) {
        Node &x = d[k];
        x.ly += b * x.lx + c;
        x.ry += b * x.rx + c;
        x.lb += b, x.lc += c;
    }

    void push(int k) {
        if (d[k].lb == 0 && d[k].lc == 0) return;
        apply(2 * k, d[k].lb, d[k].lc);
        apply(2 * k + 1, d[k].lb, d[k].lc);
        d[k].lb = d[k].lc = 0;
    }

    // q の右にあるノード k ([l, r)) の点のうち，q からの傾きが最小の点 (下側の接点)
    // b, c: k より上で k に伝わっていない遅延の和
    P tangent(P q, int k, int l, int r, T b, T c) const {
        while (r - l > 1) {
            const Node &x = d[k];
            T ly = x.ly + b * x.lx + c, ry = x.ry + b * x.rx + c;
            b += x.lb, c += x.lc;
            int m = (l + r) >> 1;
            // slope(q, 右端点) < slope(q, 左端点) なら右の子
            if ((W)(ry - q.y) * (x.lx - q.x) < (W)(ly - q.y) * (x.rx - q.x)) k = 2 * k + 1, l = m;
            else k = 2 * k, r = m;
        }
        return {d[k].lx, d[k].ly + b * d[k].lx + c};
    }

    // q の左にあるノード k の点のうち，q への傾きが最大の点 (下側の接点)
    P tangent_left(P q, int k, int l, int r, T b, T c) const {
        while (r - l > 1) {
            const Node &x = d[k];
            T ly = x.ly + b * x.lx + c, ry = x.ry + b * x.rx + c;
            b += x.lb, c += x.lc;
            int m = (l + r) >> 1;
            // slope(右端点, q) >= slope(左端点, q) なら右の子
            if ((W)(q.y - ry) * (q.x - x.lx) >= (W)(q.y - ly) * (q.x - x.rx)) k = 2 * k + 1, l = m;
            else k = 2 * k, r = m;
        }
        return {d[k].lx, d[k].ly + b * d[k].lx + c};
    }

    // 子の凸包から k の橋を計算する (k の遅延は 0 であること)
    // 左右の子を同時に降りる (Overmars-van Leeuwen)．左の凸包の辺 (a1, a2) と右の凸包の辺 (b1, b2) を見て，
    // 2 直線の大小を左右の境界 x = m - 1/2 で比べると，どちらかの半分が捨てられる．O(log n)
    void pull(int k, int l, int m, int r) {
        int u = 2 * k, ul = l, ur = m, w = 2 * k + 1, wl = m, wr = r;
        T ub = 0, uc = 0, wb = 0, wc = 0;
        while (ur - ul > 1 && wr - wl > 1) {
            const Node &x = d[u], &y = d[w];
            T a1y = x.ly + ub * x.lx + uc, a2y = x.ry + ub * x.rx + uc;
            T b1y = y.ly + wb * y.lx + wc, b2y = y.ry + wb * y.rx + wc;
            W dxa = x.rx - x.lx, dya = a2y - a1y, dxb = y.rx - y.lx, dyb = b2y - b1y;
            W cmp = dya * dxb - dyb * dxa;  // 傾きの差 (a) - (b) の符号
            // 2 * dxa * dxb * (La(m') - Lb(m')), m' = m - 1/2
            W dlt = dxb * (2 * (W)a1y * dxa + dya * (2 * m - 1 - 2 * x.lx)) - dxa * (2 * (W)b1y * dxb + dyb * (2 * m - 1 - 2 * y.lx));
            bool go_u, right;
            if (cmp > 0) go_u = dlt >= 0, right = !go_u;   // u は左へ / w は右へ
            else go_u = dlt <= 0, right = go_u;            // u は右へ / w は左へ
            if (go_u) {
                ub += x.lb, uc += x.lc;
                int um = (ul + ur) >> 1;
                if (right) u = 2 * u + 1, ul = um;
                else u = 2 * u, ur = um;
            } else {
                wb += y.lb, wc += y.lc;
                int wm = (wl + wr) >> 1;
                if (right) w = 2 * w + 1, wl = wm;
                else w = 2 * w, wr = wm;
            }
        }
        P s, t;
        if (ur - ul == 1) {
            s = {d[u].lx, d[u].ly + ub * d[u].lx + uc};
            t = tangent(s, w, wl, wr, wb, wc);
        } else {
            t = {d[w].lx, d[w].ly + wb * d[w].lx + wc};
            s = tangent_left(t, u, ul, ur, ub, uc);
        }
        d[k].lx = s.x, d[k].ly = s.y, d[k].rx = t.x, d[k].ry = t.y;
    }

    // ノード k の最小値 (k の遅延まで反映した値)
    T node_min(int k, int l, int r) const {
        T b = 0, c = 0;
        while (r - l > 1) {
            const Node &x = d[k];
            T ly = x.ly + b * x.lx + c, ry = x.ry + b * x.rx + c;
            b += x.lb, c += x.lc;
            int m = (l + r) >> 1;
            if (ry < ly) k = 2 * k + 1, l = m;
            else k = 2 * k, r = m;
        }
        return d[k].ly + b * d[k].lx + c;
    }

    void add(int k, int l, int r, int ql, int qr, T b, T c) {
        if (ql <= l && r <= qr) return apply(k, b, c);
        push(k);
        int m = (l + r) >> 1;
        if (ql < m) add(2 * k, l, m, ql, qr, b, c);
        if (m < qr) add(2 * k + 1, m, r, ql, qr, b, c);
        pull(k, l, m, r);
    }

    T query(int k, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return node_min(k, l, r);
        push(k);
        int m = (l + r) >> 1;
        if (qr <= m) return query(2 * k, l, m, ql, qr);
        if (m <= ql) return query(2 * k + 1, m, r, ql, qr);
        return std::min(query(2 * k, l, m, ql, qr), query(2 * k + 1, m, r, ql, qr));
    }

    void set(int k, int l, int r, int i, T x) {
        if (r - l == 1) {
            d[k].ly = d[k].ry = x;
            return;
        }
        push(k);
        int m = (l + r) >> 1;
        if (i < m) set(2 * k, l, m, i, x);
        else set(2 * k + 1, m, r, i, x);
        pull(k, l, m, r);
    }
};
