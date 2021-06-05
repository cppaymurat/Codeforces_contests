#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> ans;
  for(int i = k + 1; i <= n; i++) ans.push_back(i);
  for(int i = k - 1; i >= 1; i--)
    if (i >= (k - i)) ans.push_back(i);
  cout << (int) ans.size() << endl;
  for(int x : ans) {
    cout << x << ' ';
  }
  cout << endl;
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
