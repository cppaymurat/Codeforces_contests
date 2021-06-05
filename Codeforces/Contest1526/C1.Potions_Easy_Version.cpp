#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

const int N = 2e5 + 5;

const int inf = 1e9 + 7;

ll t[4 * N];
ll z[4 * N];
ll a[N];
bool modify[4 * N];

void push(int tl, int tr, int v) {
    if (modify[v]) {
        t[v] += z[v];
        if (tl != tr) {
            modify[v + v + 1] = modify[v + v + 2] = 1;
            z[v + v + 1] += z[v];
            z[v + v + 2] += z[v];
        }
        modify[v] = 0;
        z[v] = 0;
    }
}

void build(int tl, int tr, int v) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) >> 1;
        build(tl, tm, v + v + 1);
        build(tm + 1, tr, v + v + 2);
        t[v] = min(t[v + v + 1], t[v + v + 2]);
    }
}

ll query(int ql, int qr, int tl, int tr, int v) {
    if (ql > tr || qr < tl) {
        return inf;
    }
    push(tl, tr, v);
    if (ql <= tl && tr <= qr) {
        return t[v];
    }
    int tm = (tl + tr) >> 1;
    return min(
               query(ql, qr, tl, tm, v + v + 1),
               query(ql, qr, tm + 1, tr, v + v + 2));
}

void update(int ql, int qr, int val, int tl, int tr, int v) {
    push(tl, tr, v);
    if (ql > tr || qr < tl) {
        return;
    }
    if (ql <= tl && tr <= qr) {
        z[v] += val;
        modify[v] = 1;
        push(tl, tr, v);
    } else {
        int tm = (tl + tr) >> 1;
        update(ql, qr, val, tl, tm, v + v + 1);
        update(ql, qr, val, tm + 1, tr, v + v + 2);
        t[v] = min(t[v + v + 1], t[v + v + 2]);
    }
}

void solve() {
    int n;
    cin >> n;
    int answer = 0;
    vector<pair<int, int>> neg;
    for(int i = 0; i < n; i += 1) {
        int x;
        cin >> x;
        if (x < 0) {
            neg.emplace_back(x, i);
        }
        if (i)
            a[i] = a[i - 1];
        if (x >= 0) {
            a[i] += x;
            answer += 1;
        }
    }
    build(0, n - 1, 0);
    sort(all(neg));
    reverse(all(neg));

//    for(int i = 0; i < n; i += 1) {
//        cout << query(i, i, 0, n - 1, 0) << ' ';
//    }
//    cout << endl;
    for(auto [val, id] : neg) {
        update(id, n - 1, val, 0, n - 1, 0);
        if (query(0, n - 1, 0, n - 1, 0) >= 0) {
            answer += 1;
//            cout << "id = " << id << endl;
//            for(int i = 0; i < n; i += 1) {
//                cout << query(i, i, 0, n - 1, 0) << ' ';
//            }
//            cout << endl;
        } else {
            update(id, n - 1, -val, 0, n - 1, 0);
        }
    }
    cout << answer << endl;
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
