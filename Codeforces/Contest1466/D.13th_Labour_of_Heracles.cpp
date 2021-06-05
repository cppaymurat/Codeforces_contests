#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

const int N = 1e5 + 5;

int w[N];
vector<int> g[N];

void solve() {
  int n;
  cin >> n;
  ll ans = 0;
  for(int i = 0; i < n; i++) {
    g[i].clear();
    cin >> w[i];
    ans += w[i];
  }
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cout << ans << ' ';
  vector<int> sharable;
  for(int i = 0; i < n; i++) {
    if (g[i].size() > 1) {
      for(int j = 1; j < g[i].size(); j++) {
        sharable.push_back(w[i]);
      }
    }
  }
  sort(all(sharable));
  reverse(all(sharable));
  if (sharable.size() < n) sharable.push_back(0);
  for(int i = 0; i + 2 < n; i++) {
    ans += sharable[i];
    cout << ans << ' ';
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
