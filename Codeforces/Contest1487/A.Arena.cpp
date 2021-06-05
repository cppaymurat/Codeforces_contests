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
  set<int> q;
  for(int i = 0; i < n; i += 1) {
    cin >> a[i];
    q.insert(a[i]);
  }
  sort(all(a));
  if (q.size() == 1) {
    cout << 0 << endl;
  } else {
    int i = 1;
    while(a[i - 1] == a[i]) i++;
    cout << n - i << endl;
  }
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
