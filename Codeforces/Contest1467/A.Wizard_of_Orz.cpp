#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 9 << endl;
  } else
  if (n == 2) {
    cout << 98 << endl;
  } else {
    cout << 989;
    n -= 3;
    int d = 0;
    while(n) {
      cout << d;
      n--;
      d++;
      d %= 10;
    }
    cout << endl;
  }
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
