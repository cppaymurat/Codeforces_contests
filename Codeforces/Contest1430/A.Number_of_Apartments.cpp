#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
void res(int a, int b, int c) {
  cout << a << ' ' << b << ' ' << c << '\n';
}
int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int rem = n % 3;
    if (rem == 0) {
      res(n / 3, 0, 0);
    } else
    if (rem == 1) {
      if (n < 7) {
        cout << -1 << endl;
        continue;
      }
      res((n - 7) / 3, 0, 1);
    } else {
      if (n < 5) {
        cout << -1 << endl;
        continue;
      }
      res((n - 5) / 3, 1, 0);
    }
  }
  return 0;
}
