#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

const int N = 305;

char a[N][N];
int n;

void solve() {
  cin >> n;
  int f = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> a[i][j];
      f += a[i][j] != '.';
    }
  }

  vector<int> X(3, 0), O(3, 0);

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if (a[i][j] == 'X') {
        X[(i + j) % 3]++;
      }
      if (a[i][j] == 'O') {
        O[(i + j) % 3]++;
      }
    }
  }
  for(int i = 0; i < 3; i++) {
    bool ok = 0;
    for(int j = 0; j < 3; j++) {
      if (i == j)
        continue;
      if (X[i] + O[j] <= f / 3) {
        ok = 1;
        for(int k = 0; k < n; k++) {
          for(int w = 0; w < n; w++) {
            if ((k + w) % 3 == i && a[k][w] == 'X') {
              a[k][w] = 'O';
            }
            if ((k + w) % 3 == j && a[k][w] == 'O') {
              a[k][w] = 'X';
            }
          }
        }
        break;
      }
    }
    if (ok)
      break;
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << a[i][j];
    }
    cout << endl;
  }
}

int main() {
  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
