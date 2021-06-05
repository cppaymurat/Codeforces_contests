#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  vector<int> w(26);
  int mx = -1;
  int id = -1;
  for(int i = 0; i < 26; i++) {
    cin >> w[i];
    if (w[i] > mx) {
      mx = w[i];
      id = i;
    }
  }
  ll now = 0;
  for(int i = 0; i < (int) s.size(); i++) {
    now += w[s[i] - 'a'] * (i + 1);
  }
  for(int i = (int) s.size() + 1; k; i++) {
    now += mx * i;
    k--;
  }
  cout << now << endl;
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
