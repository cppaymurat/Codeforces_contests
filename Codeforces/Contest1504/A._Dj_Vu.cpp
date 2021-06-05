#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  string  s;
  cin >> s;
  vector<int> cnt(26, 0);
  int n = s.size();
  for(char c : s) {
    cnt[c - 'a'] += 1;
  }
  if (cnt[0] == n) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    bool f = 0;
    for(int i = 0; i < n; i++) {
      if (f) {
        cout << s[i];
        continue;
      }
      if (s[n - i - 1] != 'a') {
        cout << 'a';
        cout << s[i];
        f = 1;
      } else {
        cout << s[i];
      }
    }
    cout << endl;
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
