#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> good = {n};
    cout << 2 << endl;
    for(int i = n - 1; i >= 1; i--) {
      int b = good.back();
      cout << b << ' ' << i << '\n';
      good.pop_back();
      good.push_back((b + i + 1) / 2);
    }
  }
  return 0;
}
