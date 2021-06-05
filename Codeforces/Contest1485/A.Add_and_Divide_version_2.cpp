#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  ll a, b;
  cin >> a >> b;

  auto f = [&] (ll x, ll y) {
    ll q = 0;
    while(x > 0) {
      x /= y;
      q++;
    }
    return q;
  };

  ll ans = 1e18;
  for(int i = 0; i <= 100; i++) {
    if (i + b <= 1) continue;
    ans = min(ans, i + f(a, b + i));
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
