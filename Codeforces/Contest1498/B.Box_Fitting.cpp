#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int n, W;
  cin >> n >> W;
  vector<int> w(n);
  vector<int> cnt(32);
  for(int i = 0; i < n; i += 1) {
    cin >> w[i];
    w[i] = log2(w[i]);
    cnt[w[i]] += 1;
  }
  int ans = 0;
  while(n > 0) {
    int cur = W;
    for(int i = 30; i >= 0; i -= 1) {
      while (cnt[i] && (1 << i) <= cur) {
        cur -= (1 << i);
        cnt[i] -= 1;
        n -= 1;
      }
    }
    ans += 1;
  }
  cout << ans << endl;
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
