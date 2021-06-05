#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

char a[501][501];
int dp[501][501];
int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        cin >> a[i][j];
        if (a[i][j] == '*') {
          dp[i][j] = 1;
          ans++;
        }
      }
    }
    for(int k = 2; k <= 250; k++) {
      for(int i = 1; i < n; i++) {
        for(int j = 1; j + 1 < m; j++) {
          if (dp[i][j] >= k - 1 && dp[i][j - 1] >= k - 1 && dp[i][j + 1] >= k - 1 && dp[i - 1][j] >= k - 1) {
            dp[i][j] = k;
            ans++;
          }
        }
      }
    }
    for(int k = 1; k <= 250; k++) {
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
          dp[i][j] = 0;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
