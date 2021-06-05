#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
    int n, x;
    cin >> n >> x;
    int t = x;
    vector<int> a(n);
    for(int i = 0; i < n; i += 1) {
        cin >> a[i];
        x -= a[i];
    }
    if (!x) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        auto bad = [&] () {
            int s = 0;
            for(int i = 0; i < n; i += 1) {
                s += a[i];
                if (s == t) {
                    return true;
                }
            }
            return false;
        };
        while(bad()) {
            random_shuffle(all(a));
        }
        for(int i = 0; i < n; i += 1) {
            cout << a[i] << ' ';
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
