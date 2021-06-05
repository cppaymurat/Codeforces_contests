#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

#define fr first
#define sc second

void solve() {
  int n;
  cin >> n;
  vector<int> k(n);
  for(int i = 0; i < n; i += 1) {
    cin >> k[i];
  }
  vector<pair<int, pair<int, int>>> queries;
  for(int i = 0; i < n; i += 1) {
    for(int j = i + 1; j < n; j += 1) {
      queries.push_back({abs(k[i] - k[j]), {i, j}});
    }
  }
  sort(all(queries));
  reverse(all(queries));
  for(int i = 0; i < queries.size(); i += 1) {
    int b = queries[i].fr;
    int A = queries[i].sc.fr + 1;
    int B = queries[i].sc.sc + 1;
    if (k[A - 1] < k[B - 1]) swap(A, B);
    cout << "? " << A << ' ' << B << endl;
    string s;
    cin >> s;
    if (s == "Yes") {
      cout << "! " << A << ' ' << B << endl;
      return;
    }
  }
  cout << "! " << 0 << ' ' << 0 << endl;
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
