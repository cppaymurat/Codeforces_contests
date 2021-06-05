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
  map<int, int> cnt;
  int mx = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]] += 1;
    mx = max(mx, cnt[a[i]]);
  }
  if (cnt.size() == 1) {
    cout << n << endl;
  } else {
    int x = mx;
    cout << max(n % 2, x - (n - x)) << endl;
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
