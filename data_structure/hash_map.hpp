#pragma once
#include "../template.hpp"

// 整数キーのハッシュマップ (オープンアドレス法・線形探査)
// unordered_map より大幅に速い．キーは 64 bit 以下の整数型
template <class Key, class Val>
struct HashMap {
    static_assert(is_integral_v<Key>, "HashMap: Key must be an integral type");

    struct Slot {
        Key key;
        Val val;
    };

    vector<Slot> slots;
    vector<uint8_t> used;
    uint32_t mask;
    int shift;
    size_t cnt = 0;
    // ハッシュ用の乱数 (奇数)．実行ごとに変わるので，狙い撃ちの入力で衝突させられにくい
    uint64_t mul;

    HashMap(size_t reserve_size = 0) {
        mul = uint64_t(chrono::steady_clock::now().time_since_epoch().count()) * 0x9E3779B97F4A7C15ULL | 1;
        mul ^= uint64_t(reinterpret_cast<uintptr_t>(this)) << 1;
        mul |= 1;
        size_t cap = 16;
        while (cap < reserve_size * 2) cap <<= 1;
        init(cap);
    }

    void init(size_t cap) {
        slots.assign(cap, Slot{});
        used.assign(cap, 0);
        mask = cap - 1;
        shift = 64 - __builtin_ctzll(cap);
    }

    // multiply-shift ハッシュ (上位ビットを使う)
    uint32_t home(Key k) const { return uint32_t((uint64_t(k) * mul) >> shift); }

    // k があればその位置，なければ k を入れるべき空き位置を返す
    uint32_t locate(Key k) const {
        uint32_t i = home(k);
        while (used[i] && slots[i].key != k) i = (i + 1) & mask;
        return i;
    }

    void grow() {
        vector<Slot> old_slots = std::move(slots);
        vector<uint8_t> old_used = std::move(used);
        init(old_slots.size() * 2);
        for (size_t i = 0; i < old_slots.size(); i++) {
            if (!old_used[i]) continue;
            uint32_t j = home(old_slots[i].key);
            while (used[j]) j = (j + 1) & mask;
            used[j] = 1;
            slots[j] = std::move(old_slots[i]);
        }
    }

    size_t size() const { return cnt; }
    bool empty() const { return cnt == 0; }

    // 要素数 n まで再ハッシュなしで入るようにする
    void reserve(size_t n) {
        while (slots.size() < n * 2) grow();
    }

    // k に対応する値への参照 (なければ Val() を挿入する)
    Val &operator[](Key k) {
        uint32_t i = locate(k);
        if (!used[i]) {
            // 負荷率 1/2 を超えたら拡張
            if ((cnt + 1) * 2 > slots.size()) {
                grow();
                i = locate(k);
            }
            used[i] = 1;
            slots[i].key = k;
            slots[i].val = Val();
            cnt++;
        }
        return slots[i].val;
    }

    bool contains(Key k) const { return used[locate(k)]; }
    size_t count(Key k) const { return contains(k); }

    // k に対応する値．なければ def
    Val get(Key k, const Val &def = Val()) const {
        uint32_t i = locate(k);
        return used[i] ? slots[i].val : def;
    }

    // k に対応する値へのポインタ．なければ nullptr
    Val *find(Key k) {
        uint32_t i = locate(k);
        return used[i] ? &slots[i].val : nullptr;
    }

    // k を削除する．削除したら true
    // 線形探査なので，後ろに続く要素を詰め直す (backward shift deletion) ことで墓標を使わない
    bool erase(Key k) {
        uint32_t i = locate(k);
        if (!used[i]) return false;
        used[i] = 0;
        cnt--;
        uint32_t j = i;
        while (true) {
            j = (j + 1) & mask;
            if (!used[j]) break;
            uint32_t h = home(slots[j].key);
            // j の要素の本来の位置 h が (i, j] の外にあれば i に移せる
            if (((j - h) & mask) >= ((j - i) & mask)) {
                slots[i] = std::move(slots[j]);
                used[i] = 1;
                used[j] = 0;
                i = j;
            }
        }
        return true;
    }

    void clear() {
        fill(used.begin(), used.end(), 0);
        cnt = 0;
    }

    // 全ての (key, val) を f(key, val) に渡す (順序は不定)
    template <class F>
    void for_each(F f) {
        for (size_t i = 0; i < slots.size(); i++) if (used[i]) f(slots[i].key, slots[i].val);
    }
};
