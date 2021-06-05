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
    for(int i = 0; i < n; i += 1) {
        cin >> a[i];
    }
    cout << n / 2 * 6 << endl;
    for(int i = 1; i <= n; i += 2) {
        cout << 2 << ' ' << i << ' ' << i + 1 << endl;
        cout << 1 << ' ' << i << ' ' << i + 1 << endl;
        cout << 1 << ' ' << i << ' ' << i + 1 << endl;
        cout << 2 << ' ' << i << ' ' << i + 1 << endl;
        cout << 1 << ' ' << i << ' ' << i + 1 << endl;
        cout << 1 << ' ' << i << ' ' << i + 1 << endl;
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
