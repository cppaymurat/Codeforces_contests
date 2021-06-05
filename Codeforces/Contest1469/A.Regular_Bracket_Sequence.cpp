#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  string s;
  cin >> s;
  int n = (int) s.size();
  if (n & 1 || s[0] == ')' || s[n - 1] == '(') {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
