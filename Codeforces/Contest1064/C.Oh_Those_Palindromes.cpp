#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> cnt(26, 0);
  for(int i = 0; i < n; i++) {
    cnt[s[i] - 'a']++;
  }
  for(int i = 0; i < 26; i++) {
    while(cnt[i]) {
      cout << (char) (i + 'a');
      cnt[i]--;
    }
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
//  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
