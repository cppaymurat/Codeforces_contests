#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> p(n);
  for(int i = 0; i < n; i++) {
    cin >> p[i];
  }
  auto good = [&] (ll m) {
    ll s = p[0] + m;
    bool bad = 0;
    for(int i = 1; i < n; i++) {
      if (p[i] * 100 > s * k) {
        bad = 1;
        break;
      }
      s += p[i];
    }
    return !bad;
  };
  ll ans = 0;
  ll l = 0, r = 1e15;
  while(r - l > 1) {
    ll m = (l + r) >> 1;
    if (good(m)) {
      r = m;
    } else {
      l = m;
    }
  }

  while(r > 0 && good(r - 1)) {
    r--;
  }
  cout << r << endl;
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

