#include <bits/stdc++.h>
using namespace std;
int main () {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    int n;
    cin >> n;
    int a[n];
    for(int j = 0; j < n; j++) {
      cin >> a[j];
    }
    sort(a, a + n);
    bool ok = 1;
    for(int j = 1; j < n; j++) {
      if (a[j] - a[j - 1] > 1) {
        ok = 0;
      }
    }
    if (ok) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
