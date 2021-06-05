#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    k++;
    for(int i = n - 1; i >= 0 && k; i--) {
      ans += a[i];
      k--;
    }
    cout << ans << endl;
  }
  return 0;
}
