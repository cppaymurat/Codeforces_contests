#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

unordered_map<ll, int> dp;

void pre() {
   for(ll i = 1; i <= 100000; i++) {
        ll w = i * i;
        dp[w * 2] = 1;
   }
   for(ll i = 1; i <= 100000; i++) {
        ll w = i * i;
        dp[w * 4] = 1;
   }
}

void solve() {
    int n;
    cin >> n;
    if (dp.count(n)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pre();
//    freopen("taskA.in", "r", stdin);
//    freopen("taskA.out", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
