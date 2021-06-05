#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

const int N = 105;

int goal[N][N];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i <= n + 1; i += 1) {
    goal[i][0] = goal[0][i] = goal[n + 1][i] = goal[i][n + 1] = 4;
  }
  for(int i = 1; i <= n * n; i++) {
    int col;
    cin >> col;
    bool ok = 0;
    int my = -1, x, y;
    auto try_isolated = [&] (int col) {
      for(int i = 1; i <= n; i += 1) {
        for(int j = 1; j <= n; j += 1) {
          if (goal[i][j] != 0) continue;
          int cnt = 0;
          for(int k = 0; k < 4; k += 1) {
            int to_x = dx[k] + i;
            int to_y = dy[k] + j;
            if (goal[to_x][to_y] != 0 && goal[to_x][to_y] != col) {
              cnt += 1;
            }
          }
          if (cnt == 4) {
            x = i, y = j;
            my = col;
            return true;
          }
        }
      }
      return false;
    };
    auto try_diagonal = [&] (int col) {
      for(int i = 1; i <= n; i += 1) {
        for(int j = 1; j <= n; j += 1) {
          if (goal[i][j] != 0) continue;
          if ((i + j) % 2 == col % 2) {
            x = i, y = j;
            return true;
          }
        }
      }
      return false;
    };
    for(int j = 1; j <= 3; j += 1) {
      if (col != j) {
        if (try_isolated(j)) {
          ok = 1;
          my = j;
          break;
        }
      }
    }
    if (!ok) {
      for(int j = 1; j <= 3; j += 1) {
        if (col != j) {
          if (try_diagonal(j)) {
            ok = 1;
            my = j;
            break;
          }
        }
      }
    }
    cout << my << ' ' << x << ' ' << y << endl;
    goal[x][y] = my;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
//  freopen("taskA.in", "r", stdin);
//  freopen("taskA.out", "w", stdout);
  int t = 1;
//  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
