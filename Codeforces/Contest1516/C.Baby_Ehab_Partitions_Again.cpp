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
    function<bool(const vector<int>&)> bad = [] (const vector<int>& a) {
        int n = a.size();
        int s = 0;
        for(int i = 0; i < n; i += 1) {
            s += a[i];
        }
        if (s & 1) {
            return false;
        }
        vector<bool> knapsack(2000 * 100 + 1, false);
        knapsack[0] = true;
        for(int i = 0; i < n; i += 1) {
            for(int j = 2000 * 100; j > 0; j -= 1) {
                if (j - a[i] >= 0 && knapsack[j - a[i]]) {
                    knapsack[j] = true;
                }
            }
        }
        if (knapsack[s / 2] == 0)
            return false;
        return true;
    };
    if (bad(a)) {
        cout << 1 << endl;
        for(int i = 0; i < n; i += 1) {
            vector<int> b = a;
            b.erase(b.begin() + i);
            if (!bad(b)) {
                cout << i + 1 << endl;
                return;
            }
        }
    } else {
        cout << 0 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("taskA.in", "r", stdin);
//    freopen("taskA.out", "w", stdout);
    int t = 1;
//    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
