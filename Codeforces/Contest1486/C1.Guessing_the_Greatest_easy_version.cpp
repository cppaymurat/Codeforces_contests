#include <bits/stdc++.h>
#include <stdio.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
//template <class c, class cmp = less<c> > using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

int ask(int l, int r) {
  cout << "? " << l << ' ' << r << endl;
  int x;
  cin >> x;
  return x;
}

void ans(int i) {
  cout << "! " << i << endl;
  exit(0);
}

int n;

void finish(int l, int r, int w) {
  if (w == 0) {
    if (r - l + 1 == 2) {
      ans(r);
    }
    if (ask(l, l + 1) == l) {
      ans(l + 1);
    } else {
      ans(r);
    }
  } else {
    if (r - l + 1 == 2) {
      ans(l);
    }
    if (ask(r - 1, r) == r) {
      ans(r - 1);
    } else {
      ans(r - 2);
    }
  }
}

void go(int lf, int rg, int w) {
  if (rg - lf + 1 <= 3) {
    finish(lf, rg, w);
  }
  if (w == 0) {
    int l = lf, r = rg;
    while (r - l > 1) {
      int m = (l + r) >> 1;
      if (ask(lf, m) == lf) {
        r = m;
      } else {
        l = m;
      }
    }
    while(lf < r - 1 && ask(lf, r - 1) == lf) r -= 1;
    ans(r);
  } else {
    int l = lf, r = rg;
    while(r - l > 1) {
      int m = (l + r) >> 1;
      if (ask(m, rg) == rg) {
        l = m;
      } else {
        r = m;
      }
    }
    while(l + 1 < rg && ask(l + 1, rg) == rg) l += 1;
    ans(l);
  }
}

void solve() {
  cin >> n;
  if (n == 2) {
    int w = ask(1, 2);
    ans(3 - w);
  }
  if (n == 3) {
    int w = ask(1, 3);
    if (w == 1) {
      if (ask(1, 2) == w) {
        ans(2);
      } else {
        ans(3);
      }
    }
    if (w == 2) {
      if (ask(1, 2) == w) {
        ans(1);
      } else {
        ans(3);
      }
    }
    if (w == 3) {
      if (ask(2, 3) == w) {
        ans(2);
      } else {
        ans(1);
      }
    }
  }
  int l = 1, r = n;
  int mx = ask(l, r);
  if (mx == 1) {
    go(l, r, 0);
  }
  if (mx == n) {
    go(l, r, 1);
  }
  int lf = ask(l, mx);
  if (lf != mx) {
    l = mx;
    if (r - l + 1 <= 3) {
      finish(l, r, 0);
    }
    go(l, r, 0);
  } else {
    r = mx;
    if (r - l + 1 <= 3) {
      finish(l, r, 1);
    }
    go(l, r, 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
//  freopen("taskA.in", "r", stdin);
//  freopen("taskA.out", "w", stdout);
  int t = 1;
//  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
