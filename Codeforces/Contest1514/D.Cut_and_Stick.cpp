#include <bits/stdc++.h>
#include <stdio.h>
#include <unordered_map>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

#define fr first
#define sc second

const int N = 3e5 + 5;

int n, q;

pair<pair<int, int>, pair<int, int>> t[4 * N];
vector<int> pos[N];
int a[N];

using node = pair<pair<int, int>, pair<int, int>>;

int get_cnt(int ql, int qr, int val) {
    int lower = lower_bound(all(pos[val]), ql) - pos[val].begin();
    int upper = upper_bound(all(pos[val]), qr) - pos[val].begin();
    return upper - lower;
}

node merge(const node& lhs, const node& rhs) {
    if (rhs.fr.fr == -1)
        return lhs;
    if (lhs.fr.fr == -1) {
        return rhs;
    }
    if (lhs.fr.fr == rhs.fr.fr) {
        return {{lhs.fr.fr, lhs.fr.sc + rhs.fr.sc}, {lhs.sc.fr, rhs.sc.sc}};
    }
    int left_cnt = get_cnt(lhs.sc.fr, lhs.sc.sc, rhs.fr.fr);
    int right_cnt = get_cnt(rhs.sc.fr, rhs.sc.sc, lhs.fr.fr);
    if (left_cnt + rhs.fr.sc > right_cnt + lhs.fr.sc) {
        return {{rhs.fr.fr, left_cnt + rhs.fr.sc}, {lhs.sc.fr, rhs.sc.sc}};
    } else {
        return {{lhs.fr.fr, right_cnt + lhs.fr.sc}, {lhs.sc.fr, rhs.sc.sc}};
    }
}

void build(int tl = 0, int tr = n - 1, int v = 0) {
    if (tl == tr) {
        t[v].fr = {a[tl], 1};
        t[v].sc = {tl, tr};
    } else {
        int tm = (tl + tr) >> 1;
        build(tl, tm, v + v + 1);
        build(tm + 1, tr, v + v + 2);
        t[v] = merge(t[v + v + 1], t[v + v + 2]);
    }
//    cout << "v = " << v << ", tl = " << t[v].sc.fr << ", tr = " << t[v].sc.sc << ", mx_cnt = " << t[v].fr.sc << ", who = " << t[v].fr.fr << endl;
}

node query(int ql, int qr, int tl = 0, int tr = n - 1, int v = 0) {
    if (ql > tr || qr < tl)
        return {{-1, 0}, {0, 0}};
    if (ql <= tl && tr <= qr) {
        return t[v];
    }
    int tm = (tl + tr) >> 1;
    return merge(query(ql, qr, tl, tm, v + v + 1), query(ql, qr, tm + 1, tr, v + v + 2));
}

void solve() {
    cin >> n >> q;
    for(int i = 0; i < n; i += 1) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    build();
    for(int i = 0; i < q; i += 1) {
        int l, r;
        cin >> l >> r;
        l -= 1, r -= 1;
        int mx = query(l, r).fr.sc;
        if (mx <= (r - l + 2) / 2) {
            cout << 1 << endl;
        } else {
            cout << 2 * mx - (r - l + 1) << endl;
        }
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