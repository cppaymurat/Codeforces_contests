#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

int n, k;
string s;

int go_left() {
  string t = s;
  int res = 0;
  int last = 0;
  for(int i = 0; i < n; i += 1) {
    if (t[i] == '*') {
      t[i] = 'x';
      res += 1;
      last = i;
      break;
    }
  }
  int p = -1;
  for(int i = n - 1; i >= 0; i -= 1) {
    if (t[i] == '*') {
      t[i] = 'x';
      res += 1;
      p = i;
      break;
    }
  }
  if (p == -1) {
    return 1;
  }
  for(int i = last; i < n;) {
    int w = -1;
    for(int j = i + k; j < p && j > i; j -= 1) {
      if (t[j] == '*') {
        t[j] = 'x';
        res += 1;
        i = j;
        w = 1;
        break;
      }
    }
    if (w == -1) {
      break;
    }
  }
  return res;
}

void solve() {
  cin >> n >> k;
  cin >> s;
  int res = go_left();
  reverse(all(s));
  res = min(res, go_left());
  cout << res << endl;
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
