#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb_128bit"
#include "../io/fastio.hpp"

// verify for fastio (128 bit 整数)

int main() {
    int t;
    fin >> t;
    while (t--) {
        __int128 a, b;
        fin >> a >> b;
        fout << a + b << '\n';
    }
    return 0;
}
