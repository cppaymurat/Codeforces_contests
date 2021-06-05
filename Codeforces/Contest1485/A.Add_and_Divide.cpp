#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int a, b;
  cin >> a >> b;
  int ans = 100;
  for(int i = 0; i <= 100; i++) {
    if (i + b <= 1) continue;
    int res = i;
    int cur_b = i + b;
    int copy_a = a;
    while(copy_a > 0) {
      copy_a /= cur_b;
      res++;
    }
    ans = min(ans, res);
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
