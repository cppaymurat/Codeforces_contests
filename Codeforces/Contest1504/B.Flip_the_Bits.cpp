#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

const int N = 3e5 + 5;

int cnt[2][2][N];

void solve() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  for(int i = 0; i < n; i++) {
    if (i > 0) {
      for(int j = 0; j < 2; j++) {
        for(int k = 0; k < 2; k++) {
          cnt[j][k][i] = cnt[j][k][i - 1];
        }
      }
    }
    cnt[0][s[i] - '0'][i] += 1;
    cnt[1][t[i] - '0'][i] += 1;
  }
  bool ok = 1;
  bool rev = false;
  for(int i = n - 1; i >= 0; i--) {
    if (s[i] != t[i] && rev) {
      continue;
    }
    if (s[i] == t[i] && !rev) {
      continue;
    }
    if (s[i] == t[i] && rev) {
      if (cnt[0][1][i] != cnt[0][0][i]) {
        ok = 0;
        break;
      }
      rev ^= 1;
      continue;
    }
    if (s[i] != t[i] && !rev) {
      if (cnt[0][1][i] != cnt[0][0][i]) {
        ok = 0;
        break;
      }
      rev ^= 1;
      continue;
    }
  }
  if (!ok) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 2; j++) {
      for(int k = 0; k < 2; k++) {
        cnt[j][k][i] = 0;
      }
    }
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
