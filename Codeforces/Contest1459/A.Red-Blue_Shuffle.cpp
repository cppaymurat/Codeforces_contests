#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

int main() {
  int t = 1;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    cin >> t;
    int r = 0, b = 0;
    for(int i = 0; i < n; i++) {
      if (s[i] > t[i]) r++; else
      if (s[i] < t[i]) b++;
    }
    if (r > b) {
      cout << "RED\n";
    } else
    if (r < b) {
      cout << "BLUE\n";
    } else {
      cout << "EQUAL\n";
    }
  }
  return 0;
}
