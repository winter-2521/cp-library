#include <bits/stdc++.h>
using namespace std;
//*/
#include <atcoder/all>
using namespace atcoder;
//*/
/*/
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//*/
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b;i++)
#define ALL(x) (x).begin(),(x).end()
#define dbgv(x); for(auto now : x) cout << now << " "; cout << endl;
//using P = pair<int,int>;
using ll = long long;
using ull = unsigned long long;
//*/
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vint;

void solve(){
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1; //cin >> t;
  rep(testcase,t) solve();
}