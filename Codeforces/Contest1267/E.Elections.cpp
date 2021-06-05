#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

int main() {
  int n, m;
  cin >> m >> n;
  vector<vector<int>> a(n, vector<int>(m));
  vector<int> sum(m, 0);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> a[i][j];
      sum[j] += a[i][j];
    }
  }
  vector<int> best(101);
  for(int i = 0; i + 1 < m; i++) {
    set<pair<int, int>> elections;
    for(int x = 0; x < n; x++) {
      elections.insert({a[x][i] - a[x].back(), x});
    }
    int hero = sum[i];
    int enemy = sum.back();
    vector<int> res;
    while(hero < enemy) {
      auto it = elections.begin();
      int idx = it->second;
      enemy -= a[idx].back();
      hero -= a[idx][i];
      elections.erase(elections.begin());
      res.push_back(idx + 1);
    }
    if (res.size() < best.size()) {
      best = res;
    }
  }
  cout << (int) best.size() << endl;
  for(int& x : best)
    cout << x << ' ';
  return 0;
}
