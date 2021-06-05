#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

const int N = 2e5 + 1;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if (s[i] == '0') {
      cnt += 1;
    }
  }
  if (s[0] == '0' || s.back() == '0' || cnt & 1) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  string a = "", b = "";
  bool w = 0;
  for(int i = 0; i < n; i++) {
    if (s[i] == '0') {
      if (!w) {
        a += '(';
        b += ')';
        w ^= 1;
      } else {
        a += ')';
        b += '(';
        w ^= 1;
      }
    } else {
      a += 'x';
      b += 'x';
    }
  }
  int p = (n - cnt) / 2;
  int bal_a = 0, bal_b = 0;
  for(int i = 0; i < n; i += 1) {
    if (s[i] == '0') continue;
    if (p) {
      a[i] = '(';
      b[i] = '(';
      p -= 1;
    } else {
      a[i] = ')';
      b[i] = ')';
    }
  }
  cout << a << endl << b << endl;
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
