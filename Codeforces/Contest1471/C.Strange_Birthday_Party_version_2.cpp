#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

#define fr first
#define sc second

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> k(n);
  vector<int> c(m);
  for(int i = 0; i < n; i++) {
    cin >> k[i].fr;
    k[i].fr--;
    k[i].sc = i;
  }
  multiset<int> cost;
  for(int i = 0; i < m; i++) {
    cin >> c[i];
    cost.insert(c[i]);
  }
  sort(all(k));
  ll ans = 0;
  for(int i = n - 1; i >= 0; i--) {
    if (cost.empty()) {
      ans += c[k[i].fr];
      continue;
    }
    int best = *cost.begin();
    if (best <= c[k[i].fr]) {
      ans += best;
      cost.erase(cost.find(best));
    } else {
      ans += c[k[i].fr];
    }
  }
  cout << ans << endl;
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
