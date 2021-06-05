#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b;
    for(int i = 0; i < n; i += 1) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            b.push_back(a[i]);
        }
    }
    for(int i = 0; i < n; i += 1) {
        if (a[i] & 1) {
            b.push_back(a[i]);
        }
    }
    a = b;
    int res = 0;
    for(int i = 0; i < n; i += 1) {
        for(int j = i + 1; j < n; j += 1) {
            if (gcd(a[i], 2 * a[j]) > 1) {
                res += 1;
            }
        }
    }
    cout << res << endl;
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
