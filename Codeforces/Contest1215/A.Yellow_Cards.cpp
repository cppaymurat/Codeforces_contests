#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int a1, a2, b1, b2, c;
  cin >> a1 >> a2 >> b1 >> b2 >> c;
  if (b1 < b2) {
    swap(b1, b2);
    swap(a1, a2);
  }
  cout << min(a1 + a2, max(0, c - a1 * (b1 - 1) - a2 * (b2 - 1))) << ' ';
  int ans = 0;
  while(c >= b2 && a2) {
    ans++;
    c -= b2;
    a2--;
  }
  while(c >= b1 && a1) {
    ans++;
    c -= b1;
    a1--;
  }
  cout << ans << endl;
//  cout << min(c / b1, a1) + min((c - min(c / b1, a1) * b1) / b2, a2) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  // cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
