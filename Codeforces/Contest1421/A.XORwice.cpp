#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int main() {
//  freopen("taskA.in", "r", stdin);
//  freopen("taskA.out", "w", stdout);
  int t;
  cin >> t;
  while(t--) {
    int a, b;
    cin >> a >> b;
    cout << min(a ^ b, b ^ a) << endl;
  }
  return 0;
}
