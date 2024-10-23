#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/4/ITP1_4_A"
#define ERROR 0.0001 
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b; cin >> a >> b;
    cout << fixed << setprecision(10);
    cout << a/b << " " << a%b << " " << (long double)a/b << endl;
    return 0;
}
