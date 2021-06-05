#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

const int N = 2e5 + 5;
const int inf = 1e9;

int pref_mx[N];
int suff_mx[N];
int pref_mn[N];
int suff_mn[N];
int info[N];
int n, m;

string s;

int calc(int l, int r) {
  int lw = pref_mn[l - 1];
  int hg = pref_mx[l - 1];
  int last = info[l - 1];
  hg = max(hg, suff_mx[r + 1] + last);
  lw = min(lw, suff_mn[r + 1] + last);
  return hg - lw + 1;
}

void solve() {
  cin >> n >> m;
  cin >> s;
  s = '#' + s;
  int x = 0;
  for(int i = 1; i <= n + 1; i++) {
    pref_mx[i] = suff_mx[i] = -inf;
    pref_mn[i] = suff_mn[i] = +inf;
  }
  for(int i = 1; i <= n; i++) {
    if (s[i] == '+') {
      x++;
    } else {
      x--;
    }
    pref_mx[i] = max(pref_mx[i - 1], x);
    pref_mn[i] = min(pref_mn[i - 1], x);
    info[i] = x;
  }
  x = 0;
  suff_mn[n] = 0 - (s[n] == '-');
  suff_mx[n] = 0 + (s[n] == '+');
  for(int i = n - 1; i >= 1; i--) {
    if (s[i] == '+') {
      x++;
      suff_mx[i] = suff_mx[i + 1] + 1;
      suff_mn[i] = suff_mn[i + 1] + 1;
    } else {
      x--;
      suff_mn[i] = min(suff_mn[i + 1] - 1, -1);
      suff_mx[i] = max(suff_mx[i + 1] - 1, 0);
    }
  }
  suff_mn[n + 1] = suff_mn[n + 1] = pref_mx[0] = pref_mn[0] = 0;
  for(int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    cout << calc(l, r) << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
