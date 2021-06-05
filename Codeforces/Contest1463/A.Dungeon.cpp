#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

int main() {
  int t;
  cin >> t;
  while(t--) {
    ll a, b, c;
    cin >> a >> b >> c;
    // 7 выстрелов снимают 9 хп
    ll super_shots = (a + b + c) / 9;
    if (min({a, b, c}) < super_shots || (a + b + c) % 9 != 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}
