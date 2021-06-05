#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  bool ok = 1;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > d) {
      ok = 0;
    }
  }
  sort(all(a));
  if (ok || a[0] + a[1] <= d) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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
