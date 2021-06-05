#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int n;
  cin >> n;
  set<int> b;
  set<int> s;
  for(int i = 1; i <= n; i += 1) {
    s.insert(i);
    b.insert(i);
  }
  vector<int> a(n);
  vector<int> p(n, -1);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if (i == 0 || a[i] != a[i - 1]) {
      p[i] = a[i];
      s.erase(p[i]);
      b.erase(p[i]);
    }
  }
  vector<int> q(n, - 1);
  for(int i = 0; i < n; i += 1) {
    if (p[i] == -1) {
      p[i] = *s.begin(); s.erase(s.begin());
      q[i] = *(--b.lower_bound(q[i - 1])); b.erase(q[i]);
    } else {
      q[i] = p[i];
    }
  }
  for(int i = 0; i < n; i += 1) {
    cout << p[i] << ' ';
  }
  cout << endl;
  for(int i = 0; i < n; i += 1) {
    cout << q[i] << ' ';
  }
  cout << endl;
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
