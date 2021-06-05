#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  cout << 1;
  s[0]++;
  for(int i = 1; i < n; i++) {
    if (s[i] == '0') {
      if (s[i - 1] == '2') {
        s[i] = '1';
        cout << 1;
      } else
      if (s[i - 1] == '1') {
        s[i] = '0';
        cout << 0;
      } else
      if (s[i - 1] == '0') {
        s[i] = '1';
        cout << 1;
      }
    } else
    if (s[i] == '1') {
      if (s[i - 1] == '2') {
        s[i] = '1';
        cout << 0;
      } else
      if (s[i - 1] == '1') {
        s[i] = '2';
        cout << 1;
      } else
      if (s[i - 1] == '0') {
        s[i] = '2';
        cout << 1;
      }
    }
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
