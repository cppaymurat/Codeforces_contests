#include <bits/stdc++.h>

#define NAME "taskA"
#define scan 1

bool isFile;
using namespace std;


typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define mp make_pair
#define pb push_back
#define fr first
#define sc second

#define ins insert
#define all(v) v.begin(), v.end()
#define sz(v) (int) v.size()
#define rev(a) reverse(all(a))
#define skip continue
#define unique(a) sort(all(a));    a.resize(unique(all(a)) - a.begin())

//                D  R  U   L
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void _();
void faster() {
  _();
  if (isFile) {
      freopen(NAME".in", "r", stdin);
      freopen(NAME".out", "w", stdout);
  }
  if (scan) {
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      cout.tie(0);
  }
}
const ll  INF = 9e18;
const int inf = 2e9;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const ld  PI = acos(-1);
const ld  EPS = 1e-7;
const int N = 2e5 + 5;
const int M = 1234;
void solve() {
  string s;
  cin >> s;
  int x;
  cin >> x;
  string w = "";
  for(int i = 0; i < sz(s); i++)
    w += '1';
  for(int i = 0; i < sz(s); i++) {
    if (s[i] == '0') {
      if (i - x >= 0) {
        w[i - x] = '0';
      }
      if (i + x < sz(s)) {
        w[i + x] = '0';
      }
    }
  }
  for(int i = 0; i < sz(s); i++) {
    if (s[i] == '1') {
      if (i - x >= 0 && w[i - x] == '0' && i + x < sz(s) && w[i + x] == '0') {
        cout << -1 << endl;
        return;
      }
      if (i - x >= 0 && w[i - x] == '0' && i + x >= sz(s)) {
        cout << -1 << endl;
        return;
      }
      if (i - x < 0 && i + x < sz(s) && w[i + x] == '0') {
        cout << -1 << endl;
        return;
      }
      if (i + x >= sz(s) && i - x < 0) {
        cout << -1 << endl;
        return;
      }
    }
    if (s[i] == '0') {
      if (i - x >= 0 && w[i - x] == '1') {
        cout << -1 << endl;
        return;
      }
      if (i + x < sz(s) && w[i + x] == '1') {
        cout << -1 << endl;
        return;
      }
    }
  }
  cout << w << endl;
}
void stress() {}
void slow() {}
void _() {
//  isFile = 1;
}
int main() {
  faster();
  int t = 1;
  cin >> t;
  int id = 1;
  while(t--) {
//    cout << "Case #" << id++ << ": " << endl;
    solve();
//    prepare();
//    stress();
//    slow();
  }
  return 0;
}
