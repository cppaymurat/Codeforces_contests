#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<pair<ll, ll>> h(n);
    vector<ll> total(n, 0);
    for(int i = 0; i < n; i += 1) {
        cin >> h[i].first;
        h[i].second = i;
    }
    sort(all(h));
    vector<ll> res(n, -1);
    multiset<pair<ll, ll>> w;
    for(int i = 0; i < m; i += 1) {
        res[h.back().second] = i;
        total[i] += h.back().first;
        w.insert({total[i], i});
        h.pop_back();
    }
    while(!h.empty()) {
        ll mn = w.begin()->first;
        ll id = w.begin()->second;
        w.erase(w.begin());
        res[h.back().second] = id;
        w.insert({mn + h.back().first, id});
        h.pop_back();
    }
    cout << "YES\n";
    for(int i = 0; i < res.size(); i += 1) {
        cout << 1 + res[i] << ' ';
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
