#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

#define fr first
#define sc second

void solve() {
    int n, k;
    cin >> n >> k;
    if (k > (n - 1) / 2) {
        cout << -1 << endl;
    } else {
        vector<int> p(n);
        int l = 1, r = n;
        for(int i = 0; i < n; i += 1) {
            if (i % 2 == 0) {
                p[i] = l;
                l += 1;
            } else {
                if (k > 0) {
                    p[i] = r;
                    r -= 1;
                    k -= 1;
                } else {
                    p[i] = l;
                    l += 1;
                }
            }
            cout << p[i] << ' ';
        }
        cout << endl;
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
