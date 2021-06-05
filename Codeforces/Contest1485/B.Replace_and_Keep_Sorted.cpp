#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int n, q, k;
  cin >> n >> q >> k;
  vector<int> a(n + 2);
  a[0] = 0;
  a[n + 1] = k + 1;
  for(int i = 1; i <= n; i += 1) {
    cin >> a[i];
  }
  vector<ll> info(n + 2, 0ll);
  vector<ll> pref(n + 2, 0ll);
  for(int i = 1; i <= n; i++) {
    info[i] = a[i + 1] - a[i - 1] - 2;
    pref[i] = pref[i - 1] + info[i];
  }
  for(int i = 0; i < q; i += 1) {
    int l, r;
    cin >> l >> r;
    if (l == r) {
      cout << k - 1 << endl;
    } else {
      ll res = pref[r - 1] - pref[l];
      res += a[l + 1] - 2;
      res += k - a[r - 1] - 1;
      cout << res << endl;
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
//  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
