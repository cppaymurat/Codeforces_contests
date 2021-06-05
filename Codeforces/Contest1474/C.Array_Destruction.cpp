#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

const int N = 2e3 + 5;

vector<int> a;
vector<pair<int, int>> ans;

int n;

bool good(int s) {
  ans.clear();
  multiset<int> setik;
  for(int i = 0; i < 2 * n; i++) {
    setik.insert(a[i]);
  }
  while(!setik.empty()) {
    int mx = *setik.rbegin();
    setik.erase(setik.find(mx));
    if (setik.count(s - mx)) {
      setik.erase(setik.find(s - mx));
      ans.eb(mx, s - mx);
      s = mx;
    } else {
      ans.clear();
      return false;
    }
  }
  return true;
}

void solve() {
  cin >> n;
  a.resize(2 * n);
  for(int i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  sort(all(a));
  int j = 2 * n - 1;
  for(int i = 0; i < j; i++) {
    if (good(a[i] + a[j])) {
      cout << "YES" << endl;
      cout << a[i] + a[j] << endl;
      for(auto && [x, y] : ans) {
        cout << x << ' ' << y << endl;
      }
      return;
    }
  }
  cout << "NO" << endl;
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
