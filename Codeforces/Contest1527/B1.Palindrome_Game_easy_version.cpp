#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0, b = 0;
    bool last_rev = true;
    int cnt = 0;
    for(int i = 0; i < n; i += 1) {
        cnt += s[i] - '0';
    }
    cnt = n - cnt;
    if (n & 1) {
        if (cnt > 1 && s[n / 2] == '0') {
            cout << "ALICE" << endl;
        } else {
            cout << "BOB" << endl;
        }
    } else {
        cout << "BOB" << endl;
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
