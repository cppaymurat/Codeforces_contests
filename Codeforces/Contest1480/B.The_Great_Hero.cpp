#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int A, B, n;
  cin >> A >> B >> n;
  vector<ll> a(n), b(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll s = 0;
  for(int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<pair<ll, ll>> dmg(n);
  for(int i = 0; i < n; i++) {
    dmg[i] = {a[i] * ((b[i] + A - 1) / A), i};
  }
  sort(all(dmg));
  for(int i = 0; i < n; i++) {
    s += dmg[i].first;
  }
  if (s <= B) {
    cout << "YES\n";
  } else {
    for(int i = 0; i < n; i++) {
      ll turns = (b[i] + A - 1) / A;
      s -= turns * a[i];
      if ((s + (turns - 1) * a[i]) < B) {
        cout << "YES\n";
        return;
      }
      s += turns * a[i];
    }
    cout << "NO\n";
  }
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
