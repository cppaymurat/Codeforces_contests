#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

long double d(ll a, ll b) {
  return sqrtl(a * a + b * b);
}

void solve() {
  int n;
  cin >> n;
  vector<ll> a, b;
  for(int i = 0; i < 2 * n; i++) {
    int x, y;
    cin >> x >> y;
    x = abs(x);
    y = abs(y);
    if (x == 0) {
      a.push_back(y);
    } else {
      b.push_back(x);
    }
  }
  sort(all(a));
  sort(all(b));
  long double res1 = 0, res2 = 0;
  for(int i = 0; i < n; i++) {
    res1 += d(a[i], b[n - i - 1]);
    res2 += d(a[i], b[i]);
  }
  cout.precision(10);
  cout.fixed;
  cout << min(res1, res2) << endl;
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
