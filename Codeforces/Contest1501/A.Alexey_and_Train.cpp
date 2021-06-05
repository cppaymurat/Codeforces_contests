#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  vector<int> t(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> t[i];
  }
  int last = 0;
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    int x = a[i] - b[i - 1] + t[i];
    last += x;
    if (i == n) {
      ans = last;
    }
    int wait = (b[i] - a[i] + 1) / 2;
    last += wait;
    if (last < b[i]) {
      last = b[i];
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
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
