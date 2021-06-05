#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  pair<int , int > p[n];
  for(int i = 0 ; i < n ; i++)
    cin >> p[i].first >> p[i].second;
  bool ans = 0;
  for(int source = 0 ; source< n ; source++){
    bool used = 0;
    for(int i = 0 ; i < n ; i++){
      int d = abs(p[i].first - p[source].first);
      d+= abs(p[i].second - p[source].second);
      if(d > k)
        used = 1;
    }
    if(!used)ans = 1;
  }
  cout << (ans ? 1 : -1) << endl;
}

int main() {
  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}