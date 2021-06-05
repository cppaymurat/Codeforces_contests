#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

#define fr first
#define sc second

const int N = 505 * 505 + 5;
const int M = 505;
const ll inf = 1e18;

int n, m, k;

vector<pair<int, int>> g[N];

ll ans[M][M][21];

int f(int x, int y) {
    return x * M + y;
}

pair<int, int> get_inverse(int _hash) {
    return {_hash / M, _hash % M};
}

void globalBFS() {
    int w = k / 2;
    for(int q = 1; q <= w; q += 1) {
        for(int i = 0; i < n; i += 1) {
            for(int j = 0; j < m; j += 1) {
                int index = f(i, j);
                for(const auto& to : g[index]) {
                    ll dist = to.fr;
                    int v = to.sc;
                    pair<int, int> inv = get_inverse(v);
                    ans[i][j][q] = min(ans[i][j][q], ans[inv.fr][inv.sc][q - 1] + dist * 2);
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    for(int p = 1; p <= 10; p += 1) {
        for(int i = 0; i < n; i += 1) {
            for(int j = 0; j < m; j += 1) {
                ans[i][j][p] = inf;
            }
        }
    }
    for(int i = 0; i < n; i += 1) {
        for(int j = 0; j < m - 1; j += 1) {
            int x; cin >> x;
            g[f(i, j)].eb(x, f(i, j + 1));
            g[f(i, j + 1)].eb(x, f(i, j));
        }
    }
    for(int i = 0; i < n - 1; i += 1) {
        for(int j = 0; j < m; j += 1) {
            int x; cin >> x;
            g[f(i, j)].eb(x, f(i + 1, j));
            g[f(i + 1, j)].eb(x, f(i, j));
        }
    }

    if (k & 1) {
        for(int i = 0; i < n; i += 1) {
            for(int j = 0; j < m; j += 1) {
                cout << -1 << ' ';
            }
            cout << '\n';
        }
        return;
    }

    globalBFS();

    for(int i = 0; i < n; i += 1) {
        for(int j = 0; j < m; j += 1) {
            cout << ans[i][j][k / 2] << ' ';
        }
        cout << '\n';
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
