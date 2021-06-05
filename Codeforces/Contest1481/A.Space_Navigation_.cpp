#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int x, y;
  cin >> x >> y;
  string s;
  cin >> s;
  int x1 = 0, y1 = 0;
  map<char, int> cnt;
  for(char c : s) {
    cnt[c]++;
    if (c == 'U') y1++;
    if (c == 'D') y1--;
    if (c == 'L') x1--;
    if (c == 'R') x1++;
  }
  bool xx = 0, yy = 0;
  if (x == x1) {
    xx = 1;
  }
  if (y == y1) {
    yy = 1;
  }
  if (x < x1) {
    if (x1 - x <= cnt['R']) {
      xx = 1;
    }
  }
  if (x > x1) {
    if (x - x1 <= cnt['L']) {
      xx = 1;
    }
  }
  if (y < y1) {
    if (y1 - y <= cnt['U']) {
      yy = 1;
    }
  }
  if( y > y1) {
    if (y - y1 <= cnt['D']) {
      yy = 1;
    }
  }
  if (xx && yy) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
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
