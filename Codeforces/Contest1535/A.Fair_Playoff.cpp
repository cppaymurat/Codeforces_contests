#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
    vector<int> s(4);
    for(int i = 0; i < 4; i += 1) {
        cin >> s[i];
    }
    int p1 = max(s[0], s[1]);
    int p2 = max(s[2], s[3]);
    sort(all(s));
    if (p1 > p2) {
        swap(p1, p2);
    }
    if (p1 == s[2] && p2 == s[3]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
