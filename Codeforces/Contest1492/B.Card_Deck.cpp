#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

const int N = 1e5 + 5;

int n;
vector<int> a;
int pref[N];

void solve(vector<int>& ans, int tl, int tr) {
  if (tl > tr)
    return;
  if (tl == tr) {
    ans.push_back(a[tl]);
    return;
  }
  int id = pref[tr];
  for(int i = id; i <= tr; i += 1) {
    ans.push_back(a[i]);
  }
  solve(ans, tl, id - 1);
}

void solve() {
  cin >> n;
  a.resize(n);
  vector<int> ans;
  int id = 0;
  for(int i = 0; i < n; i += 1) {
    cin >> a[i];
    if (i == 0) {
      pref[i] = 0;
    } else {
      if (a[pref[i - 1]] > a[i]) {
        pref[i] = pref[i - 1];
      } else {
        pref[i] = i;
      }
    }
  }
  solve(ans, 0, n - 1);
  for(int i = 0; i < n; i += 1) {
    cout << ans[i] << ' ';
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
