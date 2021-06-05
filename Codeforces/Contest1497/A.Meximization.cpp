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
  vector<int> cnt(101, 0);
  for(int i = 0; i < n; i += 1) {
    cin >> a[i];
    cnt[a[i]] += 1;
  }
  for(int i = 0; i <= 100; i += 1) {
    if (cnt[i]) {
      cout << i << ' ';
      cnt[i] -= 1;
    }
  }
  for(int i = 0; i <= 100; i += 1) {
    while(cnt[i]) {
      cout << i << ' ';
      cnt[i] -= 1;
    }
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
