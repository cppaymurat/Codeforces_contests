#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long


const double eps = 1e-2;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i += 1) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 1; i <= 100; i += 1) {
        vector<int> b;
        double s = 0;
        for(int x : a) {
            s += x;
        }
        for(int x : a) {
            if (s >= x * a.size()) {
                b.push_back(x);
            }
        }
        if (b.size() != a.size()) {
            ans += a.size() - b.size();
            a = b;
        } else {
            break;
        }
    }
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
