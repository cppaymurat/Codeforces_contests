#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  map<int, int> m;
  int mx = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
    m[a[i]] = 1;
  }
  int last = 0;

  auto getMex = [&] () {
    while(m.count(last)) {
      last ++;
    }
    return last;
  };

  while(k--) {
    int mex = getMex();
    int cur = (mx + mex + 1) / 2;
    if (cur > mx) {
      cout << m.size() + k + 1 << endl;
      return;
    }
    if (m.count(cur)) {
      break;
    }
    m[cur] = 1;
    mx = max(mx, cur);
  }
  cout << m.size() << endl;
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
