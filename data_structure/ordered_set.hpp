#pragma once
#include "../template.hpp"

// 順序付き集合 (オンライン・値の先読み不要)
// 各ノードが最大 B 個の値をソート済み配列で持つ AVL 木．
// 1 ノードを 128 バイト程度にしてキャッシュ効率を上げ，ノード内は線形探索する．各操作 O(log n)
//
// 存在しない場合の戻り値は def (省略時 -1)
template <class T, int B = std::max(4, int(112 / sizeof(T)))>
struct OrderedSet {
    struct Node {
        T data[B];
        int left, right, total;  // total: 部分木の要素数
        short height, size;
    };

    vector<Node> t;
    vector<int> free_list;
    int root = 0;

    OrderedSet() { t.push_back(Node{}); }  // t[0] は番兵 (height = total = 0)

    // 初期要素 a (順不同・重複可) で O(n log n) 構築 (ソート済みなら O(n))
    OrderedSet(vector<T> a) : OrderedSet() {
        if (!is_sorted(a.begin(), a.end())) sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        int n = a.size();
        if (n == 0) return;
        // 後から挿入できるよう少し余裕を残して詰める
        int bs = std::max(1, B * 6 / 7);
        int m = (n + bs - 1) / bs;
        t.reserve(m + 1);
        vector<int> ids(m);
        for (int i = 0; i < m; i++) {
            int v = ids[i] = new_node();
            int l = i * bs, r = std::min(n, l + bs);
            for (int j = l; j < r; j++) t[v].data[j - l] = a[j];
            t[v].size = r - l;
        }
        root = build(ids, 0, m);
    }

    int size() const { return t[root].total; }
    bool empty() const { return root == 0; }

    // x を挿入する．挿入したら true，既にあれば false
    bool insert(const T &x) {
        done = false;
        root = insert(root, x);
        return done;
    }

    // x を削除する．削除したら true，なければ false
    bool erase(const T &x) {
        done = false;
        root = erase(root, x);
        return done;
    }

    bool contains(const T &x) const {
        for (int v = root; v;) {
            const Node &nd = t[v];
            if (x < nd.data[0]) v = nd.left;
            else if (nd.data[nd.size - 1] < x) v = nd.right;
            else {
                for (int i = 0; i < nd.size; i++) if (!(nd.data[i] < x)) return !(x < nd.data[i]);
                return false;
            }
        }
        return false;
    }
    size_t count(const T &x) const { return contains(x); }

    // 小さい方から k 番目 (0-indexed) の要素．k >= size() なら def
    T kth(int k, T def = T(-1)) const {
        if (k < 0 || k >= size()) return def;
        for (int v = root;;) {
            const Node &nd = t[v];
            int ls = t[nd.left].total;
            if (k < ls) v = nd.left;
            else if (k < ls + nd.size) return nd.data[k - ls];
            else k -= ls + nd.size, v = nd.right;
        }
    }

    // x 未満の要素の個数
    int count_lt(const T &x) const {
        int res = 0;
        for (int v = root; v;) {
            const Node &nd = t[v];
            if (!(nd.data[0] < x)) v = nd.left;
            else if (nd.data[nd.size - 1] < x) res += nd.total - t[nd.right].total, v = nd.right;
            else {
                int i = 0;
                while (nd.data[i] < x) i++;
                return res + t[nd.left].total + i;
            }
        }
        return res;
    }

    // x 以下の要素の個数
    int count_le(const T &x) const {
        int res = 0;
        for (int v = root; v;) {
            const Node &nd = t[v];
            if (x < nd.data[0]) v = nd.left;
            else if (!(x < nd.data[nd.size - 1])) res += nd.total - t[nd.right].total, v = nd.right;
            else {
                int i = 0;
                while (!(x < nd.data[i])) i++;
                return res + t[nd.left].total + i;
            }
        }
        return res;
    }

    // [lo, hi) に含まれる要素の個数
    int count_range(const T &lo, const T &hi) const { return lo < hi ? count_lt(hi) - count_lt(lo) : 0; }

    // x 未満の最大の要素 (なければ def)
    T max_lt(const T &x, T def = T(-1)) const {
        for (int v = root; v;) {
            const Node &nd = t[v];
            if (!(nd.data[0] < x)) v = nd.left;
            else if (nd.data[nd.size - 1] < x) def = nd.data[nd.size - 1], v = nd.right;
            else {
                int i = 1;
                while (nd.data[i] < x) i++;
                return nd.data[i - 1];
            }
        }
        return def;
    }

    // x 以下の最大の要素 (なければ def)
    T max_le(const T &x, T def = T(-1)) const {
        for (int v = root; v;) {
            const Node &nd = t[v];
            if (x < nd.data[0]) v = nd.left;
            else if (!(x < nd.data[nd.size - 1])) def = nd.data[nd.size - 1], v = nd.right;
            else {
                int i = 1;
                while (!(x < nd.data[i])) i++;
                return nd.data[i - 1];
            }
        }
        return def;
    }

    // x 以上の最小の要素 (なければ def)
    T min_ge(const T &x, T def = T(-1)) const {
        for (int v = root; v;) {
            const Node &nd = t[v];
            if (!(nd.data[0] < x)) def = nd.data[0], v = nd.left;
            else if (nd.data[nd.size - 1] < x) v = nd.right;
            else {
                int i = 1;
                while (nd.data[i] < x) i++;
                return nd.data[i];
            }
        }
        return def;
    }

    // x より大きい最小の要素 (なければ def)
    T min_gt(const T &x, T def = T(-1)) const {
        for (int v = root; v;) {
            const Node &nd = t[v];
            if (x < nd.data[0]) def = nd.data[0], v = nd.left;
            else if (!(x < nd.data[nd.size - 1])) v = nd.right;
            else {
                int i = 1;
                while (!(x < nd.data[i])) i++;
                return nd.data[i];
            }
        }
        return def;
    }

    // 最小の要素 / 最大の要素 (空なら def)
    T min(T def = T(-1)) const {
        if (!root) return def;
        int v = root;
        while (t[v].left) v = t[v].left;
        return t[v].data[0];
    }
    T max(T def = T(-1)) const {
        if (!root) return def;
        int v = root;
        while (t[v].right) v = t[v].right;
        return t[v].data[t[v].size - 1];
    }

    // 要素を昇順に列挙
    vector<T> to_vector() const {
        vector<T> res;
        res.reserve(size());
        auto dfs = [&](auto self, int v) -> void {
            if (!v) return;
            self(self, t[v].left);
            res.insert(res.end(), t[v].data, t[v].data + t[v].size);
            self(self, t[v].right);
        };
        dfs(dfs, root);
        return res;
    }

  private:
    bool done = false;

    int new_node() {
        int v;
        if (!free_list.empty()) v = free_list.back(), free_list.pop_back();
        else v = t.size(), t.emplace_back();
        Node &nd = t[v];
        nd.left = nd.right = 0, nd.size = 0, nd.height = 1, nd.total = 0;
        return v;
    }

    int build(const vector<int> &ids, int l, int r) {
        int m = (l + r) / 2, v = ids[m];
        t[v].left = l < m ? build(ids, l, m) : 0;
        t[v].right = m + 1 < r ? build(ids, m + 1, r) : 0;
        update(v);
        return v;
    }

    void update(int v) {
        Node &nd = t[v];
        nd.height = std::max(t[nd.left].height, t[nd.right].height) + 1;
        nd.total = nd.size + t[nd.left].total + t[nd.right].total;
    }
    int balance_factor(int v) const { return t[t[v].left].height - t[t[v].right].height; }

    int rotate_right(int v) {
        int l = t[v].left;
        t[v].left = t[l].right, t[l].right = v;
        update(v), update(l);
        return l;
    }
    int rotate_left(int v) {
        int r = t[v].right;
        t[v].right = t[r].left, t[r].left = v;
        update(v), update(r);
        return r;
    }
    // update(v) 済みであること
    int balance(int v) {
        int bf = balance_factor(v);
        if (bf == 2) {
            if (balance_factor(t[v].left) < 0) t[v].left = rotate_left(t[v].left);
            return rotate_right(v);
        }
        if (bf == -2) {
            if (balance_factor(t[v].right) > 0) t[v].right = rotate_right(t[v].right);
            return rotate_left(v);
        }
        return v;
    }

    // ノード内に挿入 (size < B であること)．既にあれば false
    bool node_insert(Node &nd, const T &x) {
        int i = 0;
        while (i < nd.size && nd.data[i] < x) i++;
        if (i < nd.size && !(x < nd.data[i])) return false;
        for (int j = nd.size; j > i; j--) nd.data[j] = nd.data[j - 1];
        nd.data[i] = x, nd.size++;
        return true;
    }
    bool node_erase(Node &nd, const T &x) {
        int i = 0;
        while (i < nd.size && nd.data[i] < x) i++;
        if (i == nd.size || x < nd.data[i]) return false;
        for (int j = i + 1; j < nd.size; j++) nd.data[j - 1] = nd.data[j];
        nd.size--;
        return true;
    }
    // 満杯のノード v の後半を新しいノードに移して，その番号を返す
    int split(int v) {
        int u = new_node();
        constexpr int h = B / 2;
        for (int i = 0; i < B - h; i++) t[u].data[i] = t[v].data[h + i];
        t[u].size = B - h, t[v].size = h;
        return u;
    }

    // 部分木 v の全要素より小さい x を挿入する
    int insert_leftmost(int v, const T &x) {
        if (t[v].left) {
            int l = insert_leftmost(t[v].left, x);
            t[v].left = l;
            update(v);
            return balance(v);
        }
        node_insert(t[v], x);
        if (t[v].size < B) {
            update(v);
            return v;
        }
        int u = split(v);
        t[u].left = v, t[u].right = t[v].right, t[v].right = 0;
        update(v), update(u);
        return balance(u);
    }

    int insert(int v, const T &x) {
        if (!v) {
            v = new_node();
            t[v].data[0] = x, t[v].size = 1;
            update(v);
            done = true;
            return v;
        }
        if (t[v].left && x < t[v].data[0]) {
            int l = insert(t[v].left, x);
            t[v].left = l;
        } else if (t[v].right && t[v].data[t[v].size - 1] < x) {
            int r = insert(t[v].right, x);
            t[v].right = r;
        } else {
            done = node_insert(t[v], x);
            if (t[v].size == B) {
                if (t[v].right) {
                    // 最大の要素を右部分木の先頭に回す
                    T y = t[v].data[--t[v].size];
                    int r = insert_leftmost(t[v].right, y);
                    t[v].right = r;
                } else {
                    int u = split(v);
                    update(u);
                    t[v].right = u;
                }
            }
        }
        update(v);
        return balance(v);
    }

    // 部分木 v の最も左のノードを切り離す (u に入れる)．残った部分木の根を返す
    int cut_leftmost(int v, int &u) {
        if (!t[v].left) {
            u = v;
            return t[v].right;
        }
        int l = cut_leftmost(t[v].left, u);
        t[v].left = l;
        update(v);
        return balance(v);
    }

    int erase(int v, const T &x) {
        if (!v) return 0;
        if (x < t[v].data[0]) {
            int l = erase(t[v].left, x);
            t[v].left = l;
        } else if (t[v].data[t[v].size - 1] < x) {
            int r = erase(t[v].right, x);
            t[v].right = r;
        } else {
            done = node_erase(t[v], x);
            if (t[v].size == 0) {
                // 空になったノードを木から外す
                free_list.push_back(v);
                if (!t[v].left || !t[v].right) return t[v].left ? t[v].left : t[v].right;
                int u = 0;
                int r = cut_leftmost(t[v].right, u);
                t[u].left = t[v].left, t[u].right = r;
                update(u);
                return balance(u);
            }
        }
        update(v);
        return balance(v);
    }
};
