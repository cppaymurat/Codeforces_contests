#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

int main() {
  int t = 1;
//  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    ll g = 0;
    ll mn = 1e18 + 5;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(all(a));
    for(int i = n - 1; i > 0; i--) {
      a[i] = a[i] - a[i - 1];
      g = gcd(g, a[i]);
    }
    for(int i = 0; i < m; i++) {
      ll x;
      cin >> x;
      cout << gcd(g, a[0] + x) << ' ';
    }
    cout << endl;
  }
  return 0;
}
