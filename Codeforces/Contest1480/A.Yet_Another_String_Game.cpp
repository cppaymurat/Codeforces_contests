#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  string s;
  cin >> s;
  for(int i = 0; i < s.size(); i++) {
    if (i % 2 == 0) {
      if (s[i] == 'a') {
        s[i] = 'b';
      } else {
        s[i] = 'a';
      }
    } else {
      if (s[i] == 'z') {
        s[i] = 'y';
      } else {
        s[i] = 'z';
      }
    }
  }
  cout << s << endl;
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
