#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

ll pw2[63];

int main() {
  pw2[0] = 1;
  for(int i = 1; i < 62; i++) {
    pw2[i] = pw2[i - 1] * 2;
  }
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    ll s = 0;
    ll q = 0;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      vector<pair<ll, ll>> candidates;
      for(int j = 0; j < 62; j++) {
        candidates.eb(abs(pw2[j] - a[i]), 1ll * j);
      }
      sort(all(candidates));
      s += a[i];
      for(int j = 0; j < 62; j++) {
        if (pw2[candidates[j].second] <= 1e9) {
          cout << pw2[candidates[j].second] << ' ';
          q += candidates[j].first;
          break;
        }
      }
    }
    cout << endl;
  }
  return 0;
}
