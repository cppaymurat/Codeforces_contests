#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

int ask(const vector<int>& some_part) {
  cout << "? ";
  for(int i = 0; i < 100; i++) {
    if (i > 0)
      cout << ' ';
    cout << some_part[i];
  }
  cout << '\n';

  fflush(stdout);

  int mask;
  cin >> mask;

  return mask;
}

void solve() {
  vector<int> first_part, second_part;
  vector<bool> used(1 << 14, false);

  for(int i = 0; i < (1 << 14); i++) {
    int cnt = 0;
    for(int j = 0; j < 7; j++) {
      if ((i >> j) & 1) {
        cnt++;
      }
    }
    if (cnt == 7) {
      first_part.push_back(i);
      used[i] = 1;
    }
  }

  for(int i = 0; i < (1 << 14); i++) {
    int cnt = 0;
    for(int j = 7; j < 14; j++) {
      if ((i >> j) & 1) {
        cnt++;
      }
    }
    if (cnt == 7) {
      if (!used[i]) {
        second_part.push_back(i);
      }
    }
  }

  int ans = 0;

  int first_mask = ask(first_part);

  for(int i = 0; i < 7; i++) {
    if (((first_mask >> i) & 1) == 0) {
      ans |= (1 << i);
    }
  }

  int second_mask = ask(second_part);

  for(int i = 7; i < 14; i++) {
    if (((second_mask >> i) & 1) == 0) {
      ans |= (1 << i);
    }
  }

  cout << "! " << ans << '\n';
  fflush(stdout);
}

int main() {
  int t = 1;
  // cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
