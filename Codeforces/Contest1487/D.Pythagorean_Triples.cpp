#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

ll f(ll v) {
  return (v * v + 1) / 2;
}

void solve() {
  ll n;
  cin >> n;
  ll l = 0, r = 1e9;
  while(r - l > 1) {
    ll m = (l + r) >> 1;
    ll v = 2 * m + 1;
    if (f(v) <= n) {
      l = m;
    } else {
      r = m;
    }
  }

  while(l + 1 <= r && f((l + 1) * 2 + 1)) l++;

  cout << l - 1 << endl;
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
