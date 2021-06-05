#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

const int N = 2e5 + 5;

int mn[N];
int mx[N];

void solve() {
  for(int i = 0; i < N; i += 1) {
    mn[i] = N + 1;
    mx[i] = -1;
  }
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  int j = 0;
  for(int i = 0; i < m; i += 1) {
    while(s[j] != t[i]) {
      j += 1;
    }
    mn[i] = j;
    j += 1;
  }
  j = n - 1;
  for(int i = m - 1; i >= 0; i -= 1) {
    while(s[j] != t[i]) {
      j -= 1;
    }
    mx[i] = j;
    j -= 1;
  }
  int ans = 0;
  for(int i = 0; i < n; i += 1) {
    if (i + 1 < n) {
      ans = max(ans, mx[i + 1] - mn[i]);
    }
    if (i > 0) {
      ans = max(ans, mx[i] - mn[i - 1]);
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
//  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
