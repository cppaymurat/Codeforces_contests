#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

bool good(string a, string b) {
  int k = a.size() / b.size();
  string t = "";
  for(int i = 0; i < k; i++) {
    t += b;
  }
  return t == a;
}

void solve() {
  string s, t;
  cin >> s >> t;
  if (s.size() > t.size()) {
    swap(s, t);
  }
  bool ok = 1;
  if (t.substr(0, s.size()) != s) {
    cout << -1 << endl;
    return;
  }
  int n = s.size();
  int m = t.size();
  int q = (n * m) / gcd(n, m);
  string p = "";
  for(int i = 0; i < q; i++) {
    p += t[i % m];
  }
  if (good(p, t) && good(p, s)) {
    cout << p << endl;
  } else {
    cout << -1 << endl;
  }
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
