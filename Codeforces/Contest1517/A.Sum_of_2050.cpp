#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

#define fr first
#define sc second

void solve() {
    ll x;
    cin >> x;
    if (x % 2050) {
        cout << -1 << endl;
    } else {
        int ans = 0;
        while(true) {
            for(ll w = 2050; w <= x; w *= 10) {
                if ((w * 10) > x && w <= x) {
                    ans += 1;
                    x -= w;
                    break;
                }
            }
            if (x == 0) {
                break;
            }
        }
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("taskA.in", "r", stdin);
//    freopen("taskA.out", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
