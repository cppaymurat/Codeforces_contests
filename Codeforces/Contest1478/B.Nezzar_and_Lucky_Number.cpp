#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

bool good(int x, int d) {
  while(x > 0) {
    if (d == x % 10) {
      return true;
    }
    x /= 10;
  }
  return false;
}

void solve() {
  int n, d;
  cin >> n >> d;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    bool ok = 0;
    for(int j = 0; j < 100 && x >= 0; j++) {
      if (good(x, d)) {
        ok = 1;
        break;
      }
      x -= d;
    }
    if (ok) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
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
