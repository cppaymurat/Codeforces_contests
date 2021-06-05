#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

namespace MATH_CAL {
    const ll mod = 1e9 + 7;
    inline ll add(ll a, ll b) { return a + b >= mod ? a + b - mod : a + b; }
    inline ll sub(ll a, ll b) { return a - b < 0 ? a - b + mod : a - b; }
    inline ll mul(ll a, ll b) { return (ll) a * b % mod; }
    inline void Add(ll &a, ll b) { (a += b) >= mod ? a -= mod : 0; }
    inline void Sub(ll &a, ll b) { (a -= b) < 0 ? a += mod : 0; }
    inline ll qpow(ll x, ll n) { ll r = 1; for ( ; n; n /= 2, x = mul(x, x)) if (n & 1) r = mul(r, x); return r; }
    inline ll mod_inv(ll x) { return qpow(x, mod - 2); }
    inline ll gcd(ll a, ll b) {while(b) {a %= b; swap(a, b);} return a;}
    inline ll lcm(ll a, ll b) {return a * b / gcd(a, b);}
} using namespace MATH_CAL;

void solve() {
  int n;
  cin >> n;
  if (n == 3) {
    cout << 2 << endl;
    cout << 3 << ' ' << 2 << endl;
    cout << 3 << ' ' << 2 << endl;
    return;
  }
  int best = 2, pw = -1;
  for(int i = 3; i <= n; i++) {
    for(int j = 1; j <= 9; j++) {
      if (qpow(i, j) >= n && qpow(2, 9 - j) >= i) {
        best = i;
        pw = j;
        break;
      }
    }
    if (pw != -1)
      break;
  }
  vector<pair<int, int>> ans;
  for(int i = n - 1; i > best; i--) {
    ans.eb(i, n);
  }
  for(int i = 1; i <= pw; i++) {
    ans.eb(n, best);
  }
  for(int i = best - 1; i > 2; i--) {
    ans.eb(i, best);
  }
  int x = best;
  for(int i = 1; x > 1; i++) {
    ans.eb(best, 2);
    x = (x + 1) / 2;
  }
  cout << ans.size() << endl;
  for(auto&& [x, y] : ans) {
    cout << x << ' ' << y << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
