#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main() {
//  freopen("taskA.in", "r", stdin);
//  freopen("taskA.out", "w", stdout);
  int t;
  cin >> t;
  auto relax = [&] (vector<ll>& c) {
    c[1] = min(c[1], c[2] + c[6]);
    c[2] = min(c[2], c[3] + c[1]);
    c[3] = min(c[3], c[2] + c[4]);
    c[4] = min(c[4], c[5] + c[3]);
    c[5] = min(c[5], c[4] + c[6]);
    c[6] = min(c[6], c[5] + c[1]);
  };
  while(t--) {
    ll x, y;
    cin >> x >> y;
    vector<ll> c(7);
    for(int i = 1; i <= 6; i++) {
      cin >> c[i];
    }
    relax(c);
    ll ans = 0;
    if (x <= 0 && y <= 0) {
      ll z = -max(x, y);
      ans += c[4] * z;
      x += z, y += z;
      if (x < 0) {
        ans += -x * c[3];
      } else
      if (y < 0) {
        ans += -y * c[5];
      }
      cout << ans << endl;
      continue;
    }
    if (x <= 0 && y >= 0) {
      ans += -x * c[3] + y * c[2];
      cout << ans << endl;
      continue;
    }
    if (x >= 0 && y <= 0) {
      ans += x * c[6] - y * c[5];
      cout << ans << endl;
      continue;
    }
    if (x >= 0 && y >= 0) {
      ll z = min(x, y);
      ans += z * c[1];
      x -= z, y -= z;
      if (x > 0) {
        ans += x * c[6];
      } else
      if (y > 0) {
        ans += y * c[2];
      }
      cout << ans << endl;
      continue;
    }
  }
  return 0;
}
