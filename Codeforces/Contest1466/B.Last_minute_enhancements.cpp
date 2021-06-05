#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> cnt(2 * n + 1);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    cnt[a[i]]++;
  }
  for(int i = 2 * n - 1; i >= 0; i--) {
    if (cnt[i]) {
      if (!cnt[i + 1]) {
        cnt[i]--;
        cnt[i + 1]++;
      }
    }
  }
  int ans = 0;
  for(int i = 0; i <= 2 * n; i++) {
    ans += cnt[i] > 0;
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
