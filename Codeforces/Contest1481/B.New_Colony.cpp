#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  for(int i = 0; i < n; i++) {
    cin >> h[i];
  }
  int ans = -1;
  for(int iter = 0; k > 0; iter++) {
    bool was = 0;
    int eq = 0;
    for(int j = 0; j + 1 < n; j++) {
      if (h[j] < h[j + 1]) {
        h[j]++;
        k--;
        if (k == 0) {
          ans = j;
        }
        was = 1;
        break;
      } else
      if (h[j] >= h[j + 1]) {
        eq++;
      }
    }
    if (!was || eq + 1 == n) {
      cout << -1 << endl;
      return;
    }
  }
  cout << ans + 1 << endl;
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
