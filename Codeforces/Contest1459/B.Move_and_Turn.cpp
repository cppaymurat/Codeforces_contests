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
    int n;
    cin >> n;
    int sign = 1;
    if (n % 2 == 0)
      sign *= -1;
    ll res = (3 * n * n + 12 * n + 2 + sign * (n * n + 4 * n + 2)) / 8;
    cout << res + 1 << endl;
  }
  return 0;
}
