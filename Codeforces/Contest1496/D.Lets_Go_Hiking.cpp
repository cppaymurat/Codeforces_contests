#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> l(n), r(n);
  int mx = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int w = 0;
  for(int i = 1; i < n; i++) {
    if (a[i - 1] < a[i]) {
      w += 1;
    } else {
      w = 0;
    }
    l[i] = w;
    mx = max(mx, w);
  }
  w = 0;
  for(int i = n - 1; i > 0; i--) {
    if (a[i - 1] > a[i]) {
      w += 1;
    } else {
      w = 0;
    }
    r[i - 1] = w;
    mx = max(mx, w);
  }

  w = 0;
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if (r[i] == mx) {
      cnt += 1;
    } else
    if (l[i] == mx) {
      cnt += 1;
    }
  }

  int ans = 0;

  for(int i = 0; i < n; i++) {
    if (l[i] && r[i] && l[i] == r[i] && l[i] % 2 == 0 && ((cnt > 1 && l[i] > mx) || (cnt == 1 && l[i] >= mx))) {
      ans++;
    }
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
//  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
