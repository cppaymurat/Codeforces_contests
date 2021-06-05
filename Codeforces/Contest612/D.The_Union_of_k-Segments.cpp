#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<pair<int, int>> t;
  for(int i = 0; i < n; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    t.eb(l, -1);
    t.eb(r, 1);
  }
  sort(all(t));
  int cnt = 0;
  int prev = 0;
  int l;
  vector<pair<int, int>> ans;
  for(auto &&[x, y] : t) {
    if (y < 0) {
      cnt++;
      if (prev == k - 1 && cnt == k) {
        l = x;
      }
    } else {
      cnt--;
      if (prev == k && cnt == k - 1) {
        ans.eb(l, x);
      }
    }
    prev = cnt;
  }
  printf("%d\n", (int) ans.size());
  for(int i = 0; i < (int) ans.size(); i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
