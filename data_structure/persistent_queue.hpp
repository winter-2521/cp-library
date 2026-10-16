#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// 永続キュー (Persistent Queue)．どの版にも push / pop でき，新しい版の番号を返す
// 追加した要素を「親 = 1 つ前の末尾」とする木で持ち，版は (末尾のノード, 先頭の深さ) の組．
// 先頭の要素 = 末尾のノードの祖先のうち深さが 先頭の深さ + 1 のもの．祖先は skew-binary の跳び先で O(log n) で求める
// push O(1)，pop・front O(log n)
template <class T>
struct PersistentQueue {
    struct Node {
        T val;
        int par, jump, depth;
    };
    vector<Node> nodes;                 // nodes[0] は根 (深さ 0，要素なし)
    vector<pair<int, int>> versions;    // (末尾のノード, 先頭の深さ)．versions[0] は空のキュー

    PersistentQueue() {
        nodes.push_back({T(), 0, 0, 0});
        versions.push_back({0, 0});
    }

    void reserve(int n) { nodes.reserve(n + 1), versions.reserve(n + 1); }

    // 空のキューの版の番号
    static constexpr int empty_version() { return 0; }

    int size(int v) const { return nodes[versions[v].first].depth - versions[v].second; }
    bool empty(int v) const { return size(v) == 0; }

    // 版 v の末尾に x を追加した版を作り，その番号を返す
    int push(int v, const T &x) {
        auto [tail, head] = versions[v];
        int p = tail;
        // skew-binary の跳び先: 親の跳び先の跳び先と深さの差がそろっていればそこへ，でなければ親
        int j = p, pj = nodes[p].jump, dep = nodes[p].depth;
        if (dep - nodes[pj].depth == nodes[pj].depth - nodes[nodes[pj].jump].depth) j = nodes[pj].jump;
        nodes.push_back({x, p, j, dep + 1});
        versions.push_back({(int)nodes.size() - 1, head});
        return versions.size() - 1;
    }

    // 版 v の先頭の要素 (空でないこと)
    T front(int v) const {
        auto [tail, head] = versions[v];
        return nodes[ancestor(tail, head + 1)].val;
    }

    // 版 v の先頭を削除した版を作り，その番号を返す (空でないこと)
    int pop(int v) {
        auto [tail, head] = versions[v];
        versions.push_back({tail, head + 1});
        return versions.size() - 1;
    }

  private:
    // ノード x の祖先で深さが dep のもの
    int ancestor(int x, int dep) const {
        while (nodes[x].depth > dep) {
            int j = nodes[x].jump;
            x = nodes[j].depth >= dep ? j : nodes[x].par;
        }
        return x;
    }
};
