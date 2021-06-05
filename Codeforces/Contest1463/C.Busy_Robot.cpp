#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<ll> t(n), x(n);
    ll cur_end = 0;
    ll pos = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
      cin >> t[i] >> x[i];
    }
    t.push_back(1e18 + 5);
    bool increasing = 1;
    ll last_start = 0;
    ll last_pos = 0;
    for(int i = 0; i < n; i++) {
      if (t[i] >= cur_end) {
        if (x[i] > pos) {
          increasing = 1;
        } else {
          increasing = 0;
        }
        cur_end = t[i] + abs(pos - x[i]);
        if (t[i + 1] >= cur_end) {
          ans++;
        }
        last_pos = pos;
        pos = x[i];
        last_start = t[i];
      } else {
        if (increasing) {
          ll position_now = last_pos + (t[i] - last_start);
          ll current_time = t[i];
          ll will_move = pos - position_now;
          if (x[i] >= position_now && position_now + will_move >= x[i]) {
            ll will_reach = x[i] - position_now;
            if (t[i + 1] - t[i] >= will_reach)
              ans++;
          }
        } else {
          ll position_now = last_pos - (t[i] - last_start);
          ll current_time = t[i];
          ll will_move = position_now - pos;
          if (x[i] <= position_now && position_now - will_move <= x[i]) {
            ll will_reach = position_now - x[i];
            if (t[i + 1] - t[i] >= will_reach)
              ans++;
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
