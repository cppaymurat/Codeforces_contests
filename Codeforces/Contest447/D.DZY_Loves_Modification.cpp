#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

namespace MATH_CAL {
    const int mod = 1e9 + 9;
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

const int N = 1e6 + 5;
const int M = 1e3 + 5;

ll pref_col[N];
ll pref_row[N];

int a[M][M];

ll col[M];
ll row[M];

void solve() {
  int n, m, k, p;
  cin >> n >> m >> k >> p;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int x;
      cin >> x;
      a[i][j] = x;
      col[j] += x;
      row[i] += x;
    }
  }
  priority_queue<ll> q;
  for(int i = 0; i < n; i++) {
    q.push(row[i]);
  }
  for(int i = 1; i <= k; i++) {
    if (i == 1) {
      pref_row[i] = q.top();
    } else {
      pref_row[i] = pref_row[i - 1] + q.top();
    }
    ll was = q.top();
    q.pop();
    q.push(was - m * p);
  }
  while(!q.empty()) q.pop();
  for(int i = 0; i < m; i++) {
    q.push(col[i]);
  }
  for(int i = 1; i <= k; i++) {
    if (i == 1) {
      pref_col[i] = q.top();
    } else {
      pref_col[i] = pref_col[i - 1] + q.top();
    }
    ll was = q.top();
    q.pop();
    q.push(was - n * p);
  }
  while(!q.empty()) q.pop();
  ll res = numeric_limits<ll>::min();
  for(int i = 0; i <= k; i++) {
    int from_rows = i;
    int from_cols = k - i;
    res = max(res, pref_row[from_rows] + pref_col[from_cols] - from_cols * 1ll * p * from_rows);
  }
  cout << res << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
//  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
