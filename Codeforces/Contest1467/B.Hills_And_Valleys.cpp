#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

const int N = 3e5 + 5;

int a[N];
int n;

bool check(int l, int r, int id, int val) {
  int t = a[id];
  a[id] = val;
  int cnt = 0;
  for(int i = l; i <= r && i + 1 < n && i - 1 >= 0; i++) {
    if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
      cnt++;
    }
    if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
      cnt++;
    }
  }
  a[id] = t;
  return cnt == 0;
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0, res = 0;
  vector<int> info(n, 0);
  for(int i = 1; i + 1 < n; i++) {
    if (a[i - 1] > a[i] && a[i] < a[i + 1]) {
      info[i] = 1;
      ans++;
    } else
    if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
      info[i] = 2;
      res++;
    }
  }
  ans += res;
  bool f = 0;
  for(int i = 1; i + 2 < n; i++) {
    if (info[i] == 1 && info[i + 2] == 1 && info[i + 1] == 2) {
      ans -= 3;
      f = 1;
      break;
    }
    if (info[i] == 2 && info[i + 2] == 2 && info[i + 1] == 1) {
      ans -= 3;
      f = 1;
      break;
    }
  }
  if (!f) {
    for(int i = 1; i + 1 < n; i++) {
      if (info[i] != 0 && info[i + 1] != 0) {
        if (i == 1 || i + 1 == n - 2) {
          ans -= 2;
          f = 1;
          break;
        }
      }
    }
  }
  if (!f) {
    int ok = 0;
    for(int i = 2; i + 2 < n; i++) {
      if (info[i] && info[i + 1]) {
        if (check(i - 1, i + 2, i, a[i + 1])) {
          ok = 1;
          break;
        } else
        if (check(i - 1, i + 2, i + 1, a[i])) {
          ok = 1;
          break;
        }
      }
    }
    if (ok) {
      ans -= 2;
      f = 1;
    }
  }
  if (!f) {
    ans = max(ans - 1, 0);
  }
  ans = max(ans, 0);
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
