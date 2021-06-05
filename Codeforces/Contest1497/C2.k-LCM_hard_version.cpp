#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  ll n, k;
  cin >> n >> k;
  for(int i = 1; i <= k - 3; i += 1) {
      cout << 1 << ' ';
  }
  n -= (k - 3);
  if (n & 1) {
    cout << n / 2 << ' ' << n / 2 << ' ' << 1 << endl;
  } else {
    if (n % 4 == 0) {
      cout << n / 2 << ' ' << n / 4 << ' ' << n / 4 << endl;
    } else {
      cout << 2 << ' ' << (n - 2) / 2 << ' ' << (n - 2) / 2 << endl;
    }
  }
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
