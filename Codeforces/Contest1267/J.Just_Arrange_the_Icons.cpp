#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> cnt(n + 1, 0);
    for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
      x--;
      cnt[x]++;
    }
    vector<int> cnts;
    for(int i = 0; i <= n; i++) {
      if (cnt[i]) {
        cnts.push_back(cnt[i]);
      }
      cnt[i] = 0;
    }
    sort(all(cnts));
    for(int i = 0; i < cnts.size(); i++) {
      cnt[cnts[i]]++;
    }
    cnts.resize(unique(all(cnts)) - cnts.begin());
    int res = 0;
    for(const int x : cnts) {
      res += ((x + 1) / 2) * cnt[x];
    }
    for(int s = 3; s <= cnts[0] + 1; s++) {
      bool ok = 1;
      int cur = 0;
      for(const int x : cnts) {
        int mx = (x + s - 1) / s;
        int rem = s - x % s;
        if(rem == s) rem = 0;
        if (rem > mx) {
          ok = 0;
          break;
        }
        cur += mx * cnt[x];
      }
      if (ok) {
        res = min(res, cur);
      }
    }
    cout << res << endl;
  }
  return 0;
}
