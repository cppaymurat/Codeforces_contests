#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int n, k1, k2;
  cin >> n >> k1 >> k2;
  int b1 = n - k1;
  int b2 = n - k2;
  int w, b;
  cin >> w >> b;
  if (b1 > b2) {
    swap(b1, b2);
  }
  if (k1 > k2) {
    swap(k1, k2);
  }
  if (k1 + (k2 - k1) / 2 >= w && b1 + (b2 - b1) / 2 >= b) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
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
