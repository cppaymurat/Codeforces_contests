#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    string s = "";
    for(int i = 0; i < (n + 2) / 3; i++) {
      s += "abc";
    }
    cout << s.substr(0, n) << endl;
  }
  return 0;
}
