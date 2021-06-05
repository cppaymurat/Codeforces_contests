#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

namespace MATH_CAL {
    const int mod = 1e9 + 7;
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

const int N = 1e3 + 5;

int dp[N][N][2];
int up;

int rec(int u, int v, int k, int w) {
  if (~dp[v][k][w]) {
    return dp[v][k][w];
  }
  if (k <= 0) {
    return dp[v][k][w] = 0;
  }
  if (v == 0 || v == up + 1) {
    return dp[v][k][w] = 1;
  }
  if (w == 0) {
    dp[v][k][w] = add(rec(v, v + 1, k, w), rec(v, u, k - 1, w ^ 1));
  } else {
    dp[v][k][w] = add(rec(v, v - 1, k, w), rec(v, u, k - 1, w ^ 1));
  }
  return dp[v][k][w];
}

void solve() {
  int n, k;
  cin >> n >> k;
  for(int i = 0; i <= n + 1; i += 1) {
    for(int j = 0; j <= k + 1; j += 1) {
      dp[i][j][0] = dp[i][j][1] = -1;
    }
  }
  up = n;
  cout << rec(0, 1, k, 0) << endl;
  for(int i = 0; i <= n + 1; i += 1) {
    for(int j = 0; j <= k + 1; j += 1) {
      dp[i][j][0] = dp[i][j][1] = -1;
    }
  }

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
//  freopen("taskA.in", "r", stdin);
//  freopen("taskA.out", "w", stdout);
  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
