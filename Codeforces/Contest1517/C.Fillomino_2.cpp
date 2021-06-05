#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

#define fr first
#define sc second

int a[501][501];
bool used[501][501];
int res[501][501];

int n;
int cur = 0;

void dfs(int x, int y, int col) {
    if (!used[x][y]) {
        used[x][y] = true;
        res[x][y] = col;
        cur -= 1;
        if (cur > 0 && y - 1 >= 0) {
            dfs(x, y - 1, col);
        }
        if (cur > 0 && x + 1 < n)
            dfs(x + 1, y, col);
    }
}

void solve() {
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i += 1) {
        cin >> p[i];
    }
    for(int i = 0; i < n; i += 1) {
        for(int j = i + 1; j < n; j += 1) {
            used[i][j] = true;
        }
    }
    for(int i = 0; i < n; i += 1) {
        cur = p[i];
        dfs(i, i, p[i]);
    }
    for(int i = 0; i < n; i += 1) {
        for(int j = 0; j <= i; j += 1) {
            if (!used[i][j] || res[i][j] == 0) {
                cout << -1 << endl;
                return;
            }
        }
    }
    for(int i = 0; i < n; i += 1) {
        for(int j = 0; j <= i; j += 1) {
            cout << res[i][j] << ' ';
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
//    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
