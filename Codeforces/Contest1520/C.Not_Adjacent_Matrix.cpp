#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << -1 << endl;
        return;
    }
    vector<int> matrix;
    for(int i = 1; i <= n * n; i += 1) {
        matrix.push_back(i);
    }

    vector<vector<int>> a(n, vector<int>(n));

    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    function<bool()> bad = [&] () {
        for(int i = 0, w = 0; i < n; i += 1) {
            for(int j = 0; j < n; j += 1) {
                a[i][j] = matrix[w ++];
            }
        }
        for(int i = 0; i < n; i += 1) {
            for(int j = 0; j < n; j += 1) {
                for(int k = 0; k < 4; k += 1) {
                    int to_x = dx[k] + i, to_y = dy[k] + j;
                    if (to_x >= 0 && to_x < n && to_y >= 0 && to_y < n) {
                        if (abs(a[to_x][to_y] - a[i][j]) == 1) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    };

    do {
        random_shuffle(all(matrix));
    } while(bad());

    for(int i = 0; i < n; i += 1) {
        for(int j = 0; j < n; j += 1) {
            cout << a[i][j] << ' ';
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
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
