#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

const int N = 2e3 + 5;
const int inf = 1e9 + 7;

int x, y, r, c, n, m;

char a[N][N];

pair<bool, pair<int, int>> b[N][N];

int result[N][N];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

//          D  R  U  L

ostream& operator<<(ostream &os, const pair<int, int>& p) {
  os << "{" << p.first << ", " << p.second << "}";
  return os;
}

void solve() {
  cin >> n >> m;
  cin >> r >> c;
  cin >> x >> y;

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      b[i][j] = {false, {inf, inf}};
      cin >> a[i][j];
    }
  }

  queue<pair<int, int>> q;

  q.push({r, c});

  b[r][c] = {false, {0, 0}};

  while(!q.empty()) {
    tie(r, c) = q.front();
    b[r][c].first = true;
    if (b[r][c].second.first <= x && b[r][c].second.second <= y) {
      result[r][c]++;
    }
    q.pop();
    for(int i = 0; i < 4; i++) {
      int xx = dx[i] + r;
      int yy = dy[i] + c;
      if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && a[xx][yy] == '.') {
        if (b[r][c].second.first + (i == 3) <= x && b[r][c].second.second + (i == 1) <= y) {
          bool was = 0;
          b[xx][yy].first = true;
          if (b[xx][yy] > make_pair(true, make_pair(b[r][c].second.first + (i == 3), b[r][c].second.second + (i == 1)))) {
            b[xx][yy] = make_pair(true, make_pair(b[r][c].second.first + (i == 3), b[r][c].second.second + (i == 1)));
            was = 1;
          }
          result[xx][yy]++;
          if (was) {
            q.push({xx, yy});
          }
        }
      }
    }
  }

  int ans = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++)
      if (result[i][j]) ans++;
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
//  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
