#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

vector<int> a[3];
int n[3];

ll calc1(vector<int> idx) {
  ll mn = a[idx[0]][0];
  ll mx = a[idx[2]].back();
  for(int i = 0; i < n[idx[1]]; i++) {
    mn -= a[idx[1]][i];
  }
  for(int i = 0; i + 1 < n[idx[2]]; i++) {
    mn -= a[idx[2]][i];
  }
  for(int i = 1; i < n[idx[0]]; i++) {
    mn += a[idx[0]][i];
  }
  mx -= mn;
  return mx;
}

ll calc2(vector<int> idx) {
  ll mx = a[idx[0]][0];
 ll mid = a[idx[1]][0];
  ll mn = a[idx[2]][0];
  for(int i = 1; i < n[idx[2]]; i++) {
    mid -= a[idx[2]][i];
  }
  mx -= mid;
  for(int i = 1; i < n[idx[0]]; i++) {
    mn -= a[idx[0]][i];
  }
  for(int i = 1; i < n[idx[1]]; i++) {
    mn -= a[idx[1]][i];
  }
  mx -= mn;
  return mx;
}

void solve() {
  for(int i = 0; i < 3; i++) {
    cin >> n[i];
  }
  for(int i = 0; i < 3; i++) {
    a[i].resize(n[i]);
    for(int j = 0; j < n[i]; j++) {
      cin >> a[i][j];
    }
    sort(all(a[i]));
  }
  vector<int> idx(3);
  iota(all(idx), 0);
  ll res = numeric_limits<ll>::min();
  do {
    ll cur = calc1(idx);
    if (cur > res) {
      res = cur;
    }
    cur = calc2(idx);
    if (cur > res) {
      res = cur;
    }
  } while(next_permutation(all(idx)));
  cout << res << endl;
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
