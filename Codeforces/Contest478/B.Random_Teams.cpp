#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  ll n, m;
  cin >> n >> m;
  ll full_team = (n + m - 1) / m;
  ll just_team = n / m;
  ll mx = (n - m + 1) * (n - m) / 2;
  ll mn = (n % m) * full_team * (full_team - 1) / 2 + (m - n % m) * just_team * (just_team - 1) / 2;
  cout << mn << ' ' << mx << endl;
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
