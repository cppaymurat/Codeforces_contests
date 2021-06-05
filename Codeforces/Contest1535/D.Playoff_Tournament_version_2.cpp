#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

#define fr first
#define sc second

const int N = (1 << 19) + 1;

struct node {
    int won;
    int game_id;
};

int winner[N];
int k;
int n;
int last;
map<pair<int, int>, int> idx;
unordered_map<int, pair<int, int>> rev;

node tree[N];

void build(int v = 0, int tl = 0, int tr = (1 << k) - 1) {
    tree[v].game_id = -1;
    if (tl == tr) {
        tree[v].won = 1;
        return;
    } else {
        int tm = (tl + tr) >> 1;
        build(v + v + 1, tl, tm);
        build(v + v + 2, tm + 1, tr);
        tree[v].game_id = idx[{tl, tr}];
        if (winner[tree[v].game_id] == -1) {
            tree[v].won = tree[v + v + 1].won +
                          tree[v + v + 2].won;
        } else {
            if (winner[tree[v].game_id] == 0) {
                tree[v].won = tree[v + v + 1].won;
            } else {
                tree[v].won = tree[v + v + 2].won;
            }
        }
//      cout << "v = " << v << " {" << tl << ", " << tr << "} = " << winner[tree[v].game_id] << endl;
    }
}

void update(int pos, int val, int v = 0, int tl = 0, int tr = (1 << k) - 1) {
    if (tree[v].game_id == pos) {
        //cout << "upd: v = " << v << " {" << tl << ", " << tr << "} = " << winner[tree[v].game_id] << endl;
        winner[pos] = val;
        if (winner[tree[v].game_id] == -1) {
            tree[v].won = tree[v + v + 1].won +
                          tree[v + v + 2].won;
        } else {
            if (winner[tree[v].game_id] == 0) {
                tree[v].won = tree[v + v + 1].won;
            } else {
                tree[v].won = tree[v + v + 2].won;
            }
        }
        return;
    }
    if (tl == tr) {
        return;
    } else {
        int tm = (tl + tr) >> 1;
        if (rev[pos].sc <= tm) {
            update(pos, val, v + v + 1, tl, tm);
        } else {
            update(pos, val, v + v + 2, tm + 1, tr);
        }
        if (winner[tree[v].game_id] == -1) {
            tree[v].won = tree[v + v + 1].won +
                          tree[v + v + 2].won;
        } else {
            if (winner[tree[v].game_id] == 0) {
                tree[v].won = tree[v + v + 1].won;
            } else {
                tree[v].won = tree[v + v + 2].won;
            }
        }
//            cout << "upd: v = " << v << " {" << tl << ", " << tr << "} = " << winner[tree[v].game_id] << endl;
//            cout << "cur value = " << tree[v].won << endl;
    }
}

void set_idx() {
    int id = 0;
    for(int pw = 1; pw <= k; pw += 1) {
        int l = 0, r = l + (1 << pw) - 1;
        while(r < (1 << k)) {
            idx[{l, r}] = id;
            rev[id] = {l, r};
            id++;
            l = r + 1;
            r = l + (1 << pw) - 1;
        }
    }
    /*for(auto [w, z] : idx) {
        auto [x, y] = w;
        cout << x + 1 << ", " << y + 1 << " = " << z << endl;
    }*/
}

void solve() {
    cin >> k;
    set_idx();
    n = (1 << k) - 1;
    string s;
    cin >> s;
    for(int i = 0; i < n; i += 1) {
        if (s[i] == '?') {
            winner[i] = -1;
        } else {
            winner[i] = s[i] - '0';
        }
    }
    build();
    int q;
    cin >> q;
    while(q--) {
        int p;
        char c;
        cin >> p >> c;
        p -= 1;
//        cout << "query to update: " << rev[p].fr << ' ' << rev[p].sc << '\n';
        if (c == '?') {
            update(p, -1);
        } else {
            update(p, c - '0');
        }
        cout << tree[0].won << endl;
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
