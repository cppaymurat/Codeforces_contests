#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long
#define ld long double

const int N = 1e5 + 5;

unordered_map<ll, int> possible;
map<pair<int, int>, bool> used;
ll pref[N];
int a[N];

void solve(int l, int r) {
  if (used.count({l, r}))
    return;
  if (l > r)
    return;
  if (l == r) {
    used[{l, r}] = 1;
    possible[a[l]] = 1;
    return;
  }
  used[{l, r}] = 1;
  ll sum = pref[r] - (l == 0 ? 0 : pref[l - 1]);
  possible[sum] = 1;
  int mid = (a[l] + a[r]) / 2;
  int pos = upper_bound(a + l, a + r + 1, mid) - a - 1;
  if (pos < l)
    return;
  solve(l, pos);
  solve(pos + 1, r);
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    possible.clear();
    used.clear();
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++) {
      if (i == 0)
        pref[i] = a[i];
      else
        pref[i] = pref[i - 1] + a[i];
    }
    solve(0, n - 1);
    for(int i = 0; i < m; i++) {
      ll s;
      cin >> s;
      if (possible.count(s)) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
  return 0;
}
