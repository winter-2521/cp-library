#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include "../io/fastio.hpp"

// verify for fastio (64 bit 整数)

int main() {
    int t;
    fin >> t;
    while (t--) {
        unsigned long long a, b;
        fin >> a >> b;
        fout << a + b << '\n';
    }
    return 0;
}
