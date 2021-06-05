#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void tryEnd(int ta, int tb, int sa, int sb, string& s, string& t) {
  s += "1";
  t += "0";

  sb -= 1;
  ta -= 1;

  for(int i = 0; i < sa; i += 1) {
    s += "0";
    t += "0";
  }

  for(int i = 0; i < sb; i += 1) {
    s += "1";
    t += "1";
  }
  reverse(all(s));
  reverse(all(t));
  cout << s << endl << t << endl;
}

void solve() {
  int a, b, k;
  cin >> a >> b >> k;
  if (k == 0) {
    cout << "Yes" << endl;
    for(int i = 0; i < b; i += 1) {
      cout << 1;
    }
    for(int i = 0; i < a; i += 1) {
      cout << 0;
    }
    cout << endl;
    for(int i = 0; i < b; i += 1) {
      cout << 1;
    }
    for(int i = 0; i < a; i += 1) {
      cout << 0;
    }
    cout << endl;
    return;
  }
  if (b == 1) {
    cout << "No" << endl;
    return;
  }
  if (!a) {
    cout << "No" << endl;
    return;
  }
  if (b < 2) {
    cout << "No" << endl;
  } else
  if (b == 2 && a < k) {
    cout << "No" << endl;
  } else {
    if (a + b - 2 >= k) {
      cout << "Yes" << endl;
      int sa = a, sb = b;
      int ta = a, tb = b;

      string s = "", t = "";

      s += "0";
      sa -= 1;
      t += "1";
      tb -= 1;

      k -= 1;

      for(int i = 0; k > 0 && i < a - 1; i += 1) {
        s += "0";
        t += "0";
        ta -= 1;
        sa -= 1;
        k -= 1;
      }

      if (k == 0) {
        tryEnd(ta, tb, sa, sb, s, t);
        exit(0);
      }

      for(int i = 0; k > 0 && i < b - 2; i += 1) {
        s += "1";
        t += "1";
        tb -= 1;
        sb -= 1;
        k -= 1;
      }

      if (k == 0) {
        tryEnd(ta, tb, sa, sb, s, t);
        exit(0);
      }

      s += "11";
      t += "01";

      reverse(all(s));
      reverse(all(t));

      cout << s << endl << t << endl;
    } else {
      cout << "No" << endl;
    }
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
