#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

bool good(string s, int mask) {
  string t = "";
  for(int i = 0; i < s.size(); i++) {
    if (s[i] == 'A') {
      if (mask & 1) {
        t += '(';
      } else {
        t += ')';
      }
    }
    if (s[i] == 'B') {
      if ((mask >> 1) & 1) {
        t += '(';
      } else {
        t += ')';
      }
    }
    if (s[i] == 'C') {
      if ((mask >> 2) & 1) {
        t += '(';
      } else {
        t += ')';
      }
    }
  }
  int bal = 0;
  for(int i = 0; i < t.size(); i++) {
    if (t[i] == '(') {
      bal++;
    } else {
      bal--;
    }
    if (bal < 0) {
      return false;
    }
  }
  if (bal != 0) return false;
  return true;
}

void solve() {
  string s;
  cin >> s;
  for(int i = 0; i < (1 << 3); i++) {
    if (good(s, i)) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
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
