#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  string s;
  cin >> s;
  if (is_sorted(all(s))) {
    cout << "YES\n";
  } else {
    int n = (int) s.size();
    bool gok = 0;
    for(int i = 0; i < n; i += 1) {
      int last = -2;
      bool ok = 1;
      for(int j = 0; j < i; j += 1) {
        if (s[j] == '1') {
          if (j - last < 2) {
            ok = 0;
            break;
          }
          last = j;
        }
      }
      last = -2;
      for(int j = i + 1; j < n; j += 1) {
        if (s[j] == '0') {
          if (j - last < 2) {
            ok = 0;
            break;
          }
          last = j;
        }
      }
      if (ok) {
        gok = 1;
        break;
      }
    }
    if (gok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
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
