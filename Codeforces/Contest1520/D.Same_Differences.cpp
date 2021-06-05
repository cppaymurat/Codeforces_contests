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
    unordered_map<int, int> cnt;
    for(int i = 0; i < n; i += 1) {
        cin >> a[i];
        a[i] -= i + 1;
        cnt[a[i]] += 1;
    }
    ll q = 0;
    for(auto it : cnt) {
        int x = it.first;
        int y = it.second;
        q += y * 1ll * (y - 1) / 2;
    }
    cout << q << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("taskA.in", "r", stdin);
//    freopen("taskA.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
