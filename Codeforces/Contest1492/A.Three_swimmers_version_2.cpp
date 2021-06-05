#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  ll p, a, b, c;
  cin >> p >> a >> b >> c;
  a = (p + a - 1) / a * a;
  b = (p + b - 1) / b * b;
  c = (p + c - 1) / c * c;
  cout << min({a, b, c}) - p << endl;
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
