#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int a[201][201];
bool used[100000];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n;

bool good(int x, int y) {
  return (x >= 1 && y >= 1 && x <= n && y <= n);
}

vector<int> g[100000];

int f(int x, int y) {
  return (x - 1) * n + y;
}

void dfs(int v) {
  if (used[v]) return;
  used[v] = 1;
  for(int to : g[v]) {
    dfs(to);
  }
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    cin >> n;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        char c;
        cin >> c;
        if (c == 'S' || c == 'F') {
          a[i][j] = 2;
        } else {
          a[i][j] = c - '0';
        }
      }
    }
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if (i == n && j == n) continue;
        if (a[i][j] == 2 || a[i][j] == 1) {
          for(int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (good(x, y)) {
              if (a[x][y] == 1 || a[x][y] == 2) {
                g[f(i, j)].push_back(f(x, y));
              }
            }
          }
        }
      }
    }
    dfs(f(1, 1));
    vector<pair<int, int>> ans;
    if (used[f(n, n)]) {
      if (a[1][2] == a[2][1]) {
        if (used[f(n - 1, n)]) {
          ans.emplace_back(n - 1, n);
          a[n - 1][n] ^= 1;
        }
        if (used[f(n, n - 1)]) {
          ans.emplace_back(n, n - 1);
          a[n][n - 1] ^= 1;
        }
      } else
      if (a[1][2] == 1) {
        ans.emplace_back(1, 2);
        a[1][2] ^= 1;
      } else {
        ans.emplace_back(2, 1);
        a[2][1] ^= 1;
      }
    }
    for(int i = 0; i <= n * n; i++) {
      g[i].clear();
      used[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if (i == n && j == n) continue;
        if (a[i][j] == 2 || a[i][j] == 0) {
          for(int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (good(x, y)) {
              if (a[x][y] == 0 || a[x][y] == 2) {
                g[f(i, j)].push_back(f(x, y));
              }
            }
          }
        }
      }
    }
    dfs(f(1, 1));
    if (used[f(n, n)]) {
      if (a[1][2] == a[2][1]) {
        if (used[f(n - 1, n)]) {
          ans.emplace_back(n - 1, n);
          a[n - 1][n] ^= 1;
        }
        if (used[f(n, n - 1)]) {
          ans.emplace_back(n, n - 1);
          a[n][n - 1] ^= 1;
        }
      } else
      if (a[1][2] == 0) {
        ans.emplace_back(1, 2);
        a[1][2] ^= 1;
      } else {
        ans.emplace_back(2, 1);
        a[2][1] ^= 1;
      }
    }
    cout << (int) ans.size() << endl;
    for(auto &&[x, y] : ans) {
      cout << x << ' ' << y << endl;
    }
    for(int i = 0; i <= n * n; i++) {
      g[i].clear();
      used[i] = 0;
    }
  }
  return 0;
}
