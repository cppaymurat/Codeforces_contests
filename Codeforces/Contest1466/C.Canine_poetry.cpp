#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  string s;
  cin >> s;
  int ans = 0;
  if ((int) s.size() == 2) {
    if (s[0] == s[1]) {
      cout << 1 << endl;
      return;
    }
    cout << 0 << endl;
    return;
  }
  int n = (int) s.size();
  for(int i = 1; i + 1 < n; i++) {
    if (s[i - 1] == s[i + 1] && s[i] == s[i - 1]) {
      s[i + 1] = '#';
      s[i] = '#';
      ans += 2;
    } else
    if (s[i - 1] == s[i] && s[i] != '#') {
      s[i] = '#';
      ans++;
    } else
    if (s[i - 1] == s[i + 1] && s[i - 1] != '#') {
      s[i + 1] = '#';
      ans++;
    }
  }
  for(int i = 0; i + 1 < n; i++) {
    if (s[i] == s[i + 1] && s[i] != '#') {
      ans++;
    }
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
