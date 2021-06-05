#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

const int N = 1e5 + 5;
set<pair<int, int>> diag[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    vector<int> x(n), y(n);
    int good = 0;
    for(int i = 0; i < m; i++) {
      cin >> x[i] >> y[i];
      x[i]--;
      y[i]--;
      if (x[i] != y[i]) {
        diag[x[i]].insert({x[i], y[i]});
        diag[y[i]].insert({x[i], y[i]});
      }
    }
    priority_queue<pair<int, int>> setik;
    int ans = 0;
    for(int i = 0; i < n; i++) {
      if (!diag[i].empty())
        setik.push({- (int) diag[i].size(), i});
    }
    while(!setik.empty()) {
      int sz = -setik.top().first;
      int x = setik.top().second;
      setik.pop();
      if (!sz)
        continue;
      if (make_pair(sz, x) != make_pair((int) diag[x].size(), x)) {
        if (!diag[x].empty()) {
          setik.push({- (int)diag[x].size(), x});
        }
        continue;
      }
      auto p = *begin(diag[x]);
      diag[p.first].erase(p);
      diag[p.second].erase(p);
      if (!diag[p.first].empty()) {
        setik.push({- (int) diag[p.first].size(), p.first});
      }
      if (!diag[p.second].empty()) {
        setik.push({- (int) diag[p.second].size(), p.second});
      }
      if (sz == 1) {
        ans++;
      } else {
        ans += 2;
      }
    }
    for(int i = 0; i < n; i++) {
      diag[i].clear();
    }
    cout << ans << endl;
  }
  return 0;
}
