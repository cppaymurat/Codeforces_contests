#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int r = n - 1;
    int cnt = 0;
    while(r >= 0 && s[r] == ')') {
      r--;
      cnt++;
    }
    if (n - cnt >= cnt) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}
