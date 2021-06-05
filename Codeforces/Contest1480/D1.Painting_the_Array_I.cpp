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
  vector<pair<int, int>> blocks;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int len = 0;
  int elem = a[0];
  for(int i = 0; i < n; i++) {
    if (a[i] == elem) {
      len++;
    }
    if (a[i] != elem || i == n - 1) {
      blocks.eb(elem, len);
      if (a[i] != elem && i == n - 1) {
        blocks.eb(a[i], 1);
      }
      len = 1;
      elem = a[i];
    }
  }
  stack<int> s1, s2;
  n = (int) blocks.size();
  for(int i = 0; i < n; ) {
    if (i + 1 < n && blocks[i].second && !s1.empty()) {
      if (s1.top() == blocks[i + 1].first) {
        s1.push(blocks[i].first);
        blocks[i].second -= 1;
      }
    }
    if (i + 1 < n && blocks[i].second && !s2.empty()) {
      if (s2.top() == blocks[i + 1].first) {
        s2.push(blocks[i].first);
        blocks[i].second -= 1;
      }
    }
    if (blocks[i].second && s1.empty()) {
      s1.push(blocks[i].first);
      blocks[i].second -= 1;
    }
    if (blocks[i].second && s2.empty()) {
      s2.push(blocks[i].first);
      blocks[i].second -= 1;
    }
    if (blocks[i].second && s1.top() != blocks[i].first) {
      s1.push(blocks[i].first);
      blocks[i].second -= 1;
    }
    if (blocks[i].second && s2.top() != blocks[i].first) {
      s2.push(blocks[i].first);
      blocks[i].second -= 1;
    }
    if (!s1.empty() && !s2.empty() && s1.top() == blocks[i].first && s2.top() == blocks[i].first) {
      blocks[i].second = 0;
    }
    if (!blocks[i].second) {
      i++;
    }
  }
  cout << s1.size() + s2.size() << endl;
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
