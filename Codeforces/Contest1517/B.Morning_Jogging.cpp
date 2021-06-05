#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

#define fr first
#define sc second

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> b(n, vector<int>(m)), res(n, vector<int>(m));
    multiset<int> w;
    for(int i = 0; i < n; i += 1) {
        for(int j = 0; j < m; j += 1) {
            cin >> b[i][j];
            w.insert(b[i][j]);
        }
    }
    while(w.size() > m) {
        w.erase(--w.end());
    }
    vector<bool> good(m, false);
    vector<vector<int>> swapped(n, vector<int>(m, 0));
    for(int c = 0; c < m; c += 1) {
        for(int r = 0; r < n; r += 1) {
            for(int i = 0; i < m; i += 1) {
                if (w.count(b[r][i]) && !good[c] && !swapped[r][i]) {
                    good[c] = true;
                    w.erase(w.find(b[r][i]));
                    swap(b[r][i], b[r][c]);
                    swapped[r][c] = true;
                }
            }
        }
    }
    for(int i = 0; i < n; i += 1) {
        for(int j = 0; j < m; j += 1) {
            cout << b[i][j] << ' ';
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
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
