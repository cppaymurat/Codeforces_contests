#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

ll pw[111];

bool good(ll x) {
    set<int> cnt;
    while(x > 0) {
        cnt.insert(x % 10);
        if (cnt.size() > 1) {
            return false;
        }
        x /= 10;
    }
    return true;
}

void solve() {
    ll n;
    cin >> n;
    ll w = 0;
    ll x = 1;
    for(int i = 0; x <= n && i <= 10; ) {
        if (good(x)) {
            w += 1;
            x += pw[i];
        } else {
            x += 1;
            i += 1;
        }
    }
    cout << w << endl;
}

void precalc() {
    pw[0] = 1;
    for(int i = 1; i <= 10; i += 1) {
        pw[i] = pw[i - 1] * 10 + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    precalc();
//    freopen("taskA.in", "r", stdin);
//    freopen("taskA.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
