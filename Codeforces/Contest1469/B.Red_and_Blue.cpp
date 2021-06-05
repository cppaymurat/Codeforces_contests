#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), pref_a(n, 0);
  int ans = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if (!i) {
      pref_a[i] = a[i];
    } else {
      pref_a[i] = pref_a[i - 1] + a[i];
    }
    ans = max(ans, pref_a[i]);
  }
  int m;
  cin >> m;
  vector<int> b(m), pref_b(m, 0);
  for(int i = 0; i < m; i++) {
    cin >> b[i];
    if (!i) {
      pref_b[i] = b[i];
    } else {
      pref_b[i] = pref_b[i - 1] + b[i];
    }
    ans = max(ans, pref_b[i]);
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      ans = max(ans, pref_a[i] + pref_b[j]);
    }
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
