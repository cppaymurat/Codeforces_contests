#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

int dp[5002][5002];
int main() {
//  freopen("taskA.in", "r", stdin);
//  freopen("taskA.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  s = '#' + s;
  t = '#' + t;
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - 1);
      dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] - 1);
      if (s[i] == t[j]) {
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 2);
      }
    }
  }
  for(int i = 1; i <= n + 1; i++) {
    for(int j = 1; j <= m + 1; j++) {
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << endl;
  return 0;
}
