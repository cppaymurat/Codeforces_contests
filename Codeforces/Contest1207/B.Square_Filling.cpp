#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m, 0));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  vector<pair<int, int>> ans;
  auto sum = [&] (int i, int j) {
    return a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i][j + 1];
  };
  auto go = [&] (int i, int j) {
    b[i][j] = b[i + 1][j] = b[i + 1][j + 1] = b[i][j + 1] = 1;
    ans.eb(i + 1, j + 1);
  };
  int iterations = 0;
  while(a != b && iterations < n * m) {
    for(int i = 0; i + 1 < n; i++) {
      for(int j = 0; j + 1 < m; j++) {
        if (sum(i, j) == 4) {
          go(i, j);
        }
      }
    }
    iterations++;
  }
  if (a != b) {
    cout << -1 << endl;
    return;
  }
  sort(all(ans));
  ans.resize(unique(all(ans)) - ans.begin());
  cout << ans.size() << endl;
  for(auto && [x, y] : ans) {
    cout << x << ' ' << y << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
//  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
