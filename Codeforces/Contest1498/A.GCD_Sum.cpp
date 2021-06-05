#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

bool gcdx(ll x) {
  ll s = 0;
  ll p = x;
  while(x > 0) {
    s += x % 10;
    x /= 10;
  }
  return gcd(s, p) > 1;
}

void solve() {
  ll n;
  cin >> n;
  while(!gcdx(n)) {
    n += 1;
  }
  cout << n << endl;
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
