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
  }
  vector<vector<int>> blocks;
  vector<int> cur;
  int last = -1;
  for(int i = 0; i < n; i++) {
    if (a[i] > last) {
      cur.push_back(a[i]);
    } else {
      blocks.push_back(cur);
      cur.clear();
      cur.push_back(a[i]);
    }
    last = a[i];
  }
  if (!cur.empty()) {
    blocks.push_back(cur);
  }
  int ans = 0;
  for(auto x : blocks) {
    ans = max(ans, (int) x.size());
  }
  if (blocks.size() > 1) {
    ans++;
  }
  for(int i = 1; i < (int) blocks.size(); i++) {
    int n1 = blocks[i - 1].size();
    int n2 = blocks[i].size();
    if (blocks[i].size() == 1 || blocks[i - 1].size() == 1) {
      ans = max(ans, n1 + n2);
    } else {
      if (blocks[i][0] - blocks[i - 1][n1 - 2] > 1 || blocks[i][1] - blocks[i - 1][n1 - 1] > 1) {
        ans = max(ans, n1 + n2);
      }
    }
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
//  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
