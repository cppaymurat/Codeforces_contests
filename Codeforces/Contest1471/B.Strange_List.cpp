#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  vector<int> b(n);
  ll s = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
    s += a[i];
  }
  for(int i = 0; i < 32; i++) {
    int f = 0;
    for(int j = 0; j < n; j++) {
      if (a[j] % x == 0) {
        s += b[j];
        a[j] /= x;
      } else {
        f = 1;
        break;
      }
    }
    if (f)
      break;
  }
  cout << s << endl;
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
