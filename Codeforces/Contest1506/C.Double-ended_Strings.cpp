#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  for(int len = n; len >= 1; len -= 1) {
    for(int i = 0; i + len <= n; i += 1) {
      string sub = s.substr(i, len);
      if (t.find(sub) != -1) {
        cout << n + m - len * 2 << endl;
        return;
      }
    }
  }
  cout << n + m << endl;
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
