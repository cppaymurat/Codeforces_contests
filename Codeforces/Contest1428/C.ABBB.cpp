#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int main() {
//  freopen("taskA.in", "r", stdin);
//  freopen("taskA.out", "w", stdout);
  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    int len = (int) s.size();
    stack<char> q;
    int ans = 0;
    for(int i = 0; i < len; i++) {
      if (q.empty() || s[i] == 'A') {
        q.push(s[i]);
      } else
      if (q.top() == 'A' && s[i] == 'B') {
        q.pop();
        ans += 2;
      } else {
        q.push(s[i]);
      }
    }
    string p = "";
    while(!q.empty()) {
      p += q.top();
      q.pop();
    }
    for(int i = 0; i < (int) p.size() - 1; i++) {
      if (p[i] == 'B' && p[i + 1] == 'B') {
        ans += 2;
        i++;
      }
    }
    cout << len - ans << endl;
  }
  return 0;
}
