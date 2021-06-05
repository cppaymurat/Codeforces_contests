#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int n;
  cin >> n;

  string s, t;
  cin >> s >> t;

  vector<int> cnt(26, 0);

  for(int i = 0; i < n; i++) {
    cnt[s[i] - 'a']++;
    cnt[t[i] - 'a']++;
  }

  for(int i = 0; i < 26; i++) {
    if (cnt[i] & 1) {
      cout << -1 << endl;
      return;
    }
  }

  vector<pair<int, int>> ans;
  set<int> pos[26][2];
  map<pair<int, int>, set<int>> pairs;

  for(int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      pos[s[i] - 'a'][0].insert(i);
      pos[t[i] - 'a'][1].insert(i);
      pairs[{s[i] - 'a', t[i] - 'a'}].insert(i);
    }
  }

  auto relax = [&] () {
    for(int i = 0; i < 26; i++) {
      for(int j = 0; j < 26; j++) if (i != j) {
        while (pairs.count({i, j}) && pairs[{i, j}].size() > 1) {
          int x = *pairs[{i, j}].begin();
          int y = *pairs[{i, j}].rbegin();
          ans.eb(x, y);
          pos[s[x] - 'a'][0].erase(x);
          pos[s[y] - 'a'][0].erase(y);
          pos[t[x] - 'a'][1].erase(x);
          pos[t[y] - 'a'][1].erase(y);
          swap(s[x], t[y]);
          pairs[{i, j}].erase(x);
          pairs[{i, j}].erase(y);
        }
      }
    }
  };

  for(int i = 0; i < n; i++) {
    relax();
    if (s[i] != t[i]) {
      int j = *pos[s[i] - 'a'][1].rbegin();
      ans.eb(j, j);

      pos[s[j] - 'a'][0].erase(j);
      pos[t[j] - 'a'][1].erase(j);

      pos[s[j] - 'a'][1].insert(j);
      pos[t[j] - 'a'][0].insert(j);

      swap(s[j], t[j]);

      ans.eb(j, i);

      pos[s[j] - 'a'][0].erase(j);
      pos[t[j] - 'a'][1].erase(j);
      pos[s[i] - 'a'][0].erase(i);
      pos[t[i] - 'a'][1].erase(i);

      swap(s[j], t[i]);
    }
  }

  assert(s == t);
  cout << ans.size() << endl;
  for(auto && [x, y] : ans) {
    cout << x + 1 << ' ' << y + 1 << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  // cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
