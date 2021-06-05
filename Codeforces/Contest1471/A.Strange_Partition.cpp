#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int n, x;
  cin >> n >> x;
  ll mn = 0, mx = 0;
  vector<int> a(n);
  ll s = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    mx += (a[i] + x - 1) / x;
    s += a[i];
  }
  mn = (s + x - 1) / x;
  cout << mn << ' ' << mx << endl;
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
