#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

const int N = 1e5 + 5;

vector<int> g[N];
vector<int> topsort;
bool ok = 1;
int used[N];

void dfs(int v) {
  used[v] = 1;
  for(int to : g[v]) {
    if (!used[to]) {
      dfs(to);
    } else
    if (used[to] == 1) {
      ok = 0;
    }
  }
  used[v] = 2;
  topsort.push_back(v);
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> templates(n);
  map<string, int> template_id;
  vector<string> words(m);
  vector<int> need_id(m);
  for(int i = 0; i < n; i++) {
    cin >> templates[i];
    template_id[templates[i]] = i;
  }
  for(int i = 0; i < m; i++) {
    cin >> words[i] >> need_id[i];
    need_id[i]--;
    bool bad = 1;
    for(int mask = 0; mask < (1 << k); mask++) {
      string was = words[i];
      for(int j = 0; j < k; j++) {
        if ((mask >> j) & 1) {
          was[j] = '_';
        }
      }
      if (was == templates[need_id[i]]) {
        bad = 0;
      }
      if (template_id.count(was) && need_id[i] != template_id[was]) {
        g[need_id[i]].push_back(template_id[was]);
      }
    }
    if (bad) {
      ok = 0;
      break;
    }
  }
  for(int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs(i);
    }
  }
  if (ok) {
    cout << "YES\n";
    reverse(all(topsort));
    for(int x : topsort)
      cout << x + 1 << ' ';
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
//  freopen("taskA.in", "r", stdin);
//  freopen("taskA.out", "w", stdout);
  int t = 1;
//  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}

