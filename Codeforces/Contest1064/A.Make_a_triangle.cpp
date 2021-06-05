#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  vector<int> a(3);
  cin >> a[0] >> a[1] >> a[2];
  sort(all(a));
  if (a[0] + a[1] <= a[2]) {
    cout << a[2] - a[1] - a[0] + 1 << endl;
  } else {
    cout << 0 << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
//  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
