#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int main() {
//  freopen("taskA.in", "r", stdin);
//  freopen("taskA.out", "w", stdout);
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int was = 0;
    int cur = 0;
    set<int> u;
    int l = 0;
    for(int i = 0; i < n; i++) {
      if (s[i] == 'L') {
        if (cur > 0) {
          was += cur * 2 - 1;
          cur = 0;
        }
        l++;
      } else {
        cur++;
      }
    }
    if (k >= l) {
      cout << n * 2 - 1 << endl;
      continue;
    }
    if (cur > 0)
      was += cur * 2 - 1;

    vector<pair<int, int>> blocks;
    cur = 0;
    char x = '#';
    for(int i = 0; i < n; i++) {
      if (s[i] == x) {
        cur++;
      } else {
        if (cur > 0) {
          blocks.push_back({cur, x == 'L'});
        }
        cur = 1;
        x = s[i];
      }
    }
    if (cur > 0) {
      blocks.push_back({cur, s.back() == 'L'});
    }
    int st = 0;
    int en = 0;

    int all = l;
    map<int, int> cnt;
    for(int i = 1; i < (int) blocks.size() - 1; i++) {
      if (blocks[i].second) {
        cnt[blocks[i].first]++;
        u.insert(blocks[i].first);
      }
    }

    int total = 0;

    while(!u.empty() && k > 0) {
      auto best = *u.begin();
      cnt[best]--;
      if (cnt[best] == 0) {
        u.erase(u.begin());
      }
      if (best > k) {
        break;
      }
      total += best * 2 + 1;
      all -= best;
      k -= best;
    }

    total += min(k, all) * 2;
    if (!was) total--;
    cout << max(0, total + was) << endl ;
  }
  return 0;
}
