#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
    int n;
    cin >> n;

    vector<int> bit(32);

    int cnt = 0;

    for(int i = 0; i < 32; i += 1) {
        if ((n >> i) & 1) {
            bit[i] = 1;
            cnt += 1;
        }
    }

    if (cnt == 1) {
        cout << n - 1 << endl;
        return;
    }

    int f = -1, s = -1;
    for(int i = 31; i >= 0; i -= 1) {
        if (bit[i]) {
            if (f == -1) {
                f = i;
            } else {
                s = i;
                break;
            }
        }
    }

    cout << (1 << f) - 1 << endl;
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
