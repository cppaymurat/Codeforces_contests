#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int n;
  cin >> n;
  map<ll, int> cnt;
  vector<ll> d(2 * n);
  bool ok = 1;
  for(int i = 0; i < 2 * n; i++) {
    ll x;
    cin >> x;
    d[i] = x;
    cnt[x]++;
    if (x % 2) {
      ok = 0;
    }
    if (cnt[x] > 2) {
      ok = 0;
    }
  }
  vector<ll> was = d;
  if (ok) {
    sort(all(d));
    d.resize(unique(all(d)) - d.begin());
    if (d.size() != n) {
      ok = 0;
    }
    reverse(all(d));
    ll s = 0;
    vector<ll> a(2 * n);
    vector<ll> b(n);
    for(int i = 0; i < n; i++) {
      if ((d[i] - s) % (2 * n - i * 2) != 0) {
        ok = 0;
        break;
      }
      a[i] = (d[i] - s) / (2 * n - i * 2);
      s += a[i] * 2;
      b[i] = a[i];
      a[i + n] = -a[i];
    }
    sort(all(a));
    for(int i = 1; i < 2 * n; i++) {
      if (a[i] == a[i - 1]) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      s = 0;
      vector<ll> q(2 * n);
      for(int i = 0; i < n; i++) {
        q[i] = -a[i] * (2 * n - i * 2) + s;
        s += -a[i] * 2;
        q[n + i] = q[i];
      }
      sort(all(q));
      sort(all(was));
      if (q != was) {
        ok = 0;
      }
    }
  }
  if (ok) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
