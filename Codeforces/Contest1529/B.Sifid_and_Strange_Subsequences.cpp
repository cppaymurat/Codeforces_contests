#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

const int inf = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    vector<int> b;

    int res = 0;
    int z = 0;

    int mn = inf;
    bool w = 0;

    for(int i = 0; i < n; i += 1) {
        cin >> a[i];
        if (a[i] < 0) {
            ans += 1;
            b.push_back(a[i]);
        }
        if (a[i] <= 0) {
            res += 1;
            if (!a[i]) {
                z += 1;
            }
        } else {
            mn = min(mn, a[i]);
            w = 1;
        }
    }

    sort(all(b));

    int mx = inf;

    for(int i = 0; i + 1 < b.size(); i += 1) {
        mx = min(mx, abs(b[i] - b[i + 1]));
    }

    if (w && mn <= mx) {
        ans += 1;
        b.push_back(mn);
        w = 1;
    } else {
        w = 0;
    }

    if (w && z > 0) {
        w = 1;
        for(int x : b) {
            if (abs(x) < mn) {
                w = 0;
                break;
            }
        }
        if (w) {
            ans += 1;
        }
    }

    ans = max(ans, 1);

    ans = max(ans, res);

    cout << ans << endl;
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
