#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

const int N = 1e7 + 7;

void solve() {
  ll n, k;
  cin >> n >> k;
  int ans = 0;
  vector<int> b(n);
  for(int i = 0, x; i < n; i += 1) {
    cin >> x;
    ll cur = 1;
    for(int j = 2; j * j <= x; j += 1) if (x % j == 0) {
      int cnt = 0;
      while(x % j == 0) {
        cnt += 1;
        x /= j;
      }
      if (cnt & 1) {
        cur *= j;
      }
    }
    if (x > 1) {
      cur *= x;
    }
    if (cur == 1) {
      b[i] = 16;
    } else {
      b[i] = cur;
    }
  }
  set<ll> was;
  for(int i = 0; i < n; i += 1) {
    ll cur = b[i];
    if (was.count(cur)) {
      ans += 1;
      was.clear();
      was.insert(cur);
    } else {
      was.insert(cur);
    }
  }
  cout << ans + 1 << endl;
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
