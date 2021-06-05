#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

const int N = 2e5 + 5;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> pos(k + 1, 0);
  for(int i = 0; i < k; i++) {
    a[i] = i + 1;
    pos[a[i]] = i + 1;
  }
  for(int i = k; i < n; i++) {
    a[i] = a[i - 1] - 1;
  }
  vector<int> res;
  for(int i = n - k; i < n; i++) {
    res.push_back(a[i]);
  }
  vector<bool> used(k + 1, 0);
  set<int> unused;
  for(int i = 1; i <= k; i++) unused.insert(i);
  for(int i = k - 1; i >= 0; i--) {
    if (!used[res[i]]) {
      used[res[i]] = 1;
      unused.erase(res[i]);
    } else {
      res[i] = *prev(unused.end());
      unused.erase(prev(unused.end()));
      used[res[i]] = 1;
    }
  }
  for(int i = 0; i < k; i++) {
    cout << pos[res[i]] << ' ';
  }
  cout << endl;
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
