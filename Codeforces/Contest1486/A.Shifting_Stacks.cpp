#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n + 1);
  ll s = 0;
  bool ok = 1;
  for(int i = 0; i < n; i += 1) {
    cin >> a[i];
  }
  vector<ll> need(n);
  for(int i = 0; i < n; i += 1) {
    need[i] = i;
  }
  for(int i = 0; i < n; i += 1) {
    if (a[i] < need[i]) {
      ok = 0;
      break;
    }
    a[i + 1] += a[i] - need[i];
  }
  if (ok) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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
