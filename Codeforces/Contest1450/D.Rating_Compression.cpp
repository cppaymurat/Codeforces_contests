#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

const int N = 3e5 + 5;
const int inf = 1e9 + 7;

int t[4 * N];
int a[N];
int n;

int merge(const int& a, const int& b) {
    return min(a, b);
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) >> 1;
        build(v + v + 1, tl, tm);
        build(v + v + 2, tm + 1, tr);
        t[v] = merge(t[v + v + 1], t[v + v + 2]);
    }
}

int query(int tl, int tr, int v, int ql, int qr) {
    if (tl > qr | tr < ql)
        return inf;
    if (ql <= tl && tr <= qr)
        return t[v];
    int tm = (tl + tr) >> 1;
    return merge(query(tl, tm, v + v + 1, ql, qr),
                 query(tm + 1, tr, v + v + 2, ql, qr));
}

int query(int ql, int qr) {
    return query(0, n - 1, 0, ql, qr);
}

int knt[N];

bool check(int k) {
  for(int i = 1; i <= n; i++) knt[i] = 0;
  int most = -1, least = -1;
  int sz = 0;
  for(int i = 0; i + k - 1 < n; i++) {
    int mn = query(i, i + k - 1);
    knt[mn]++;
    sz++;
    if (knt[mn] > 1)
      return false;
    if (i == 0) {
      most = mn;
    } else {
      most = max(most, mn);
    }
  }
  for(int i = 1; i <= most; i++) {
    if (!knt[i])
      return false;
  }
  return true;
}

void solve() {
  cin >> n;
  vector<int> cnt(n + 1, 0);
  vector<int> ans(n, 0);
  int mx = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
    mx = max(mx, cnt[a[i]]);
  }
  build(0, 0, n - 1);
  if (mx == 1) {
    ans[0] = 1;
  }
  int l = 1, r = n;
  while(r - l > 1) {
    int m = (l + r) >> 1;
    if (check(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  if (!check(r)) {
    for(int i = 0; i < n; i++) {
      cout << ans[i];
    }
    cout << endl;
    return;

  }
  if (r - 1 >= 1 && check(r - 1)) r--;
  r = max(r - 1, 0);
  for(int i = r; i < n; i++) {
    ans[i] = 1;
  }
  for(int &x : ans) {
    cout << x;
  }
  cout << endl;
}

int main() {
  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
