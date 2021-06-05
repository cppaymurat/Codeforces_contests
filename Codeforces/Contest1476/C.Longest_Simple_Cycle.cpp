#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<ll> c(n), b(n), a(n);
  for(int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> b[i];
  }
  ll ans = 0;
  vector<ll> d(n);
  d[n - 1] = c[n - 1] + 1;
  ans = max(ans, d[n - 1]);
  for(int i = n - 2; i >= 1; i--) {
    if (a[i + 1] != b[i + 1]) {
      ans = max(ans, abs(a[i + 1] - b[i + 1]) + d[i + 1]);
      d[i] = max(c[i] + 1, d[i + 1] + min(a[i + 1], b[i + 1]) - 1 + c[i] - max(a[i + 1], b[i + 1]) + 2);
      ans = max(ans, d[i]);
    } else {
      d[i] = c[i] + 1;
    }
  }
  ans = max(ans, d[1] + abs(a[1] - b[1]));
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

