#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> a(n);
    int z = 0;
    for(int i = 0; i < n; i += 1) {
        a[i] = s[i] - '0';
        z += 1 - a[i];
    }
    m = min(m, z);
    for(int t = 0; t < m; t += 1) {
        vector<int> b = a;
        for(int i = 0; i < n; i += 1) {
            bool left_alive = false;
            bool right_alive = false;
            if (a[i] == 1) {
                continue;
            }
            if (i > 0 && a[i - 1]) {
                left_alive = true;
            }
            if (i + 1 < n && a[i + 1]) {
                right_alive = true;
            }
            if ((int) left_alive + (int) right_alive == 1) {
                b[i] = 1;
            }
        }
        a = b;
    }
    for(int i = 0; i < n; i += 1) {
        cout << a[i];
    }
    cout << endl;
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
