#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < 0)
      a[i] = -1;
    else
      a[i] = 1;
  }
  ll pos = 0;
  vector<int> b(n);
  int sign = -1;
  map<int, int> last;
  for(int i = 0; i < n; i++) {
    if (a[i] == -1) {
      b[i] = sign;
      sign *= -1;
    } else {
      b[i] = 0;
    }
  }
  int s = 0;
  for(int i = 0; i < n; i++) {
    s += b[i];
    pos += (s == 0);
    if (last.count(s))
      pos += last[s];
    last[s]++;
  }
  cout << n * 1ll * (n + 1) / 2 - pos << ' ' << pos << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  // cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
