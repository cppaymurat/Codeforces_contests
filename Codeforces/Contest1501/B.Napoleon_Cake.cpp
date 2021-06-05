#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> pref(n + 1);
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pref[max(0, i - x + 1)] += 1;
    pref[i + 1] -= 1;
  }
  int s = 0;
  for(int i = 0; i < n; i++) {
    s += pref[i];
    cout << min(s, 1) << ' ';
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
