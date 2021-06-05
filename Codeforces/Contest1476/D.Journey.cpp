#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

const int N = 3e5 + 5;

int dp_left[N][2];
int dp_right[N][2];
int ans[N];

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for(int i = 0; i <= n; i++) {
    ans[i] = 1;
    dp_left[i][0] = dp_left[i][1] = dp_right[i][0] = dp_right[i][1] = 0;
  }
  for(int i = 1; i <= n; i++) {
    if (s[i - 1] == 'L') {
      dp_left[i][0] = dp_left[i - 1][1] + 1;
      dp_left[i][1] = 0;
    } else {
      dp_left[i][0] = 0;
      dp_left[i][1] = dp_left[i - 1][0] + 1;
    }
  }
  for(int i = n - 1; i >= 0; i--) {
    if (s[i] == 'R') {
      dp_right[i][0] = dp_right[i + 1][1] + 1;
      dp_right[i][1] = 0;
    } else {
      dp_right[i][0] = 0;
      dp_right[i][1] = dp_right[i + 1][0] + 1;
    }
  }
  for(int i = 0; i <= n; i++) {
//    cout << "i = " << i << endl;
//    cout << "dp left was = " << dp_left[i][0] << endl;
//    cout << "dp left rev = " << dp_left[i][1] << endl;
//    cout << "dp right was = " << dp_right[i][0] << endl;
//    cout << "dp right rev = " << dp_right[i][1] << endl << endl << endl;
    ans[i] = dp_left[i][0] + dp_right[i][0] + 1;
    cout << ans[i] << ' ';
  }
  cout << endl;
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

