#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long
#define ld long double

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<double> p;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
    }
    int l = 0, r = n - 1;
    while(r >= 0 && a[r] == r) r--;
    for(int i = 0; i < m; i++) {
      int pref;
      double P;
      cin >> pref >> P;
      pref--;
      if (pref >= r) {
        p.push_back(P);
      }
    }
    if (l > r) {
      cout << 1 << endl;
      continue;
    }
    ld res = 0;
    for(int i = 0; i < p.size(); i++) {
      res = p[i] + res * (1 - p[i]);
    }
    cout << setprecision(10) << res << endl;
  }
  return 0;
}
