#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

const ll MOD = 1e9 + 7;

namespace MATH_CAL {
    const ll mod = MOD;
    inline ll add(ll a, ll b) { return a + b >= mod ? (a + b) % mod : a + b; }
    inline ll sub(ll a, ll b) { return a - b < 0 ? ((a - b) % mod + mod) % mod : a - b; }
    inline ll mul(ll a, ll b) { return (ll) a * b % mod; }
    inline void Add(ll &a, ll b) { (a += b) >= mod ? a -= mod : 0; }
    inline void Sub(ll &a, ll b) { (a -= b) < 0 ? a += mod : 0; }
    inline ll qpow(ll x, ll n) { ll r = 1; for ( ; n; n /= 2, x = mul(x, x)) if (n & 1) r = mul(r, x); return r; }
    inline ll mod_inv(ll x) { return qpow(x, mod - 2); }
    inline ll gcd(ll a, ll b) {while(b) {a %= b; swap(a, b);} return a;}
    inline ll lcm(ll a, ll b) {return a * b / gcd(a, b);}
} using namespace MATH_CAL;

const int N = 5e5 + 5;

ll q[61];
ll bit[61];
ll bitx[N][61];

ll f(ll x) {
  return mul(mul(x, (x - 1)), mod_inv(2));
}

void solve() {
  int n;
  cin >> n;
  vector<ll> x(n);
  ll sum = 0;
  ll sum_or = 0;
  ll sum_and = 0;
  ll all_sum = 0;
  for(int i = 0; i < 60; i++) {
    bit[i] = 0;
  }
  for(int i = 0; i < n; i++) {
    cin >> x[i];
    all_sum += x[i];
    for(int j = 0; j < 60; j++) {
      bitx[i][j] = 0;
      if ((x[i] >> j) & 1) {
        bit[j]++;
        bitx[i][j] = 1;
      }
    }
  }
  sum = 0;
  for(int j = 0; j < n; j++) {
    sum_or = 0;
    sum_and = 0;
    for(int i = 0; i < 60; i++) {
      if (bitx[j][i]) {
        sum_or = add(sum_or, mul(q[i], n));
        sum_and = add(sum_and, mul(q[i], bit[i]));
      } else {
        sum_or = add(sum_or, mul(q[i], bit[i]));
      }
    }
    sum = add(sum, mul(sum_and, sum_or));
  }
  cout << sum << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  q[0] = 1;
  for(int i = 1; i < 60; i++) {
    q[i] = q[i - 1] * 2;
    q[i] %= MOD;
  }
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
