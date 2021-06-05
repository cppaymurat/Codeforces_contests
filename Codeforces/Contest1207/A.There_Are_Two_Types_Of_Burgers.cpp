#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int b, p, f, h, c;
  cin >> b >> p >> f >> h >> c;
  if (h < c) {
    swap(p, f);
    swap(h, c);
  }
  int ans = 0;
  while(b >= 2 && p > 0) {
    ans += h;
    b -= 2;
    p--;
  }
  while(b >= 2 && f > 0) {
    ans += c;
    b -= 2;
    f--;
  }
  cout << ans << endl;
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
