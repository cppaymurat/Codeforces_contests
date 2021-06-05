#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> b(m);
  for(int i = 0; i < n; i += 1) {
    cin >> a[i];
    a[i] %= m;
    b[a[i]] += 1;
  }
  int ans = 0;
  for(int i = 0; i < m; i += 1) {
    if (!b[i]) {
      continue;
    }
    if (i == (m - i) % m) {
      ans += 1;
      b[i] = 0;
      continue;
    }
    if (b[(m - i) % m] == 0) {
      ans += b[i];
      b[i] = 0;
      continue;
    }
    int& l = b[i];
    int& r = b[(m - i) % m];
    if (l > r)
      swap(l, r);
    r = max(0, r - l - 1);
    l = 0;
    ans += 1;
  }
  cout << ans << endl;
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
