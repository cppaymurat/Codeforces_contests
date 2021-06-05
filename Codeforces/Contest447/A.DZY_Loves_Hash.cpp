#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int p, n;
  cin >> p >> n;
  int ans = -1;
  vector<int> used(p + 1, 0);
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int h = x % p;
    if (used[h]) {
      ans = i + 1;
      break;
    }
    used[h] = 1;
  }
  cout << ans << endl;
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
