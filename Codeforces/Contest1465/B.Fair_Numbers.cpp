#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

bool good(ll n){
  if (n == 0)
    return true;
  vector<bool> digits(10, false);
  ll q = n;
  while (q) {
    if (q % 10) {
      if (n % (q % 10))
        return 0;
    }
    q /= 10;
  }
  return 1;
}

void solve(){
  ll n;
  cin >> n;
  while (!good(n))
    n++;
  cout << n << endl;
}

int main(){
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
