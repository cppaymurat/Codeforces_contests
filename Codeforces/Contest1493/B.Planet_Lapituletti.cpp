#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

int h, m;

vector<int> gds = {0, 1, 2, 5, 8};
int rev[10];

void pre() {
  rev[0] = 0;
  rev[1] = 1;
  rev[8] = 8;
  rev[5] = 2;
  rev[2] = 5;
}

bool gd(int x) {
  for(int y : gds) if (y == x) return 1;
  return 0;
}

bool good(int x, int y) {
  string t = "";
  if (x < 10) t += "0";
  t += to_string(x);
  if (y < 10) t += "0";
  t += to_string(y);
  int nx = 0;
  for(int i = 1; i >= 0; i--) {
    int y = t[i] - '0';
    if (gd(y)) {
      nx = nx * 10 + rev[y];
    } else {
      return 0;
    }
  }
  if (nx >= m) return 0;
  int ny = 0;
  for(int i = 3; i >= 2; i--) {
    int x = t[i] - '0';
    if (gd(x)) {
      ny = ny * 10 + rev[x];
    } else {
      return 0;
    }
  }
  if (ny >= h) return 0;
  return 1;
}

void solve() {
  cin >> h >> m;
  int hh, mm;
  char dummy;
  cin >> hh >> dummy >> mm;
  while(!good(hh, mm)) {
    mm++;
    if (mm == m) {
      mm = 0;
      hh++;
    }
    if (hh == h) {
      hh = 0;
    }
  }
  if (hh < 10) cout << 0;
  cout << hh << ":";
  if (mm < 10) cout << 0;
  cout << mm << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
//  freopen("taskA.in", "r", stdin);
//  freopen("taskA.out", "w", stdout);
  pre();
  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
