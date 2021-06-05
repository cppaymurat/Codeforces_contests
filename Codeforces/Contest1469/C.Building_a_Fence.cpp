#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  ll n, k;
  cin >> n >> k;
  k--;
  vector<ll> h(n);
  for(int i = 0; i < n; i++) {
    cin >> h[i];
  }
  bool bad = 0;
  ll l = h[0], r = h[0];
  for(int i = 1; i < n; i++) {
    if (h[i] > r + k) {
      bad = 1;
      break;
    }
    if (h[i] < l - 2 * k) {
      bad = 1;
      break;
    }
    l = max(h[i], l - k);
    r = min(h[i] + k, r + k);
  }
  if (l <= h[n - 1] && h[n - 1] <= r) {

  } else {
    bad = 1;
  }

  if (bad) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
