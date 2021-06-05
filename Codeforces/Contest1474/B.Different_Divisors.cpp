#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

vector<int> primes;

void pre() {
  vector<bool> prime(1e6 + 5, true);
  prime[0] = prime[1] = false;
  for(int i = 2; i <= 1e6; i++) {
    if (prime[i]) {
      for(int j = i + i; j <= 1e6; j += i) {
        prime[j] = false;
      }
      primes.push_back(i);
    }
  }
}

void solve() {
  int d;
  cin >> d;
  ll res = 1;
  ll x = (1 + d);
  ll y = *lower_bound(all(primes), x);
  res *= y;
  x = y + d;
  y = *lower_bound(all(primes), x);
  res *= y;
  cout << res << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  pre();
  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
