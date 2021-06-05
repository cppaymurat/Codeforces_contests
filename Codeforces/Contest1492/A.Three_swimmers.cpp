#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

ll find_nearest(ll x, ll p) {
  ll l = 1, r = p / x + 1;
  while(r - l > 1) {
    ll m = l + (r - l) / 2;
    if (x * m >= p) {
      r = m;
    } else {
      l = m;
    }
  }
  while (x * (r - 1) >= p) r -= 1;
  return r;
}

void solve() {
  ll p, a, b, c;
  cin >> p >> a >> b >> c;
  ll ax = find_nearest(a, p) * a;
  ll bx = find_nearest(b, p) * b;
  ll cx = find_nearest(c, p) * c;
  cout << min({ax - p, bx - p, cx - p}) << endl;
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
