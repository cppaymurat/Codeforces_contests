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
#define rep(i, l, r) for(int i = l; i < r; i++)
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
int n;
ll q[100001][64];
bool can(const vector<int>& a, int pw) {
  if (pw == 1)
    return 1;
  for(int j = 1; j < n; j++) {
    if (q[pw][j - 1] <= 0 || q[pw][j - 1] > q[pw][j] || q[pw][j] <= 0)
      return 0;
  }
  return 1;
}
ll calc(const vector<int>& a, int pw) {
  ll need = 0;
  for(int i = 0; i < n; i++) {
    need += abs(a[i] - q[pw][i]);
  }
  return need;
}
ll f(int x) {
  ll up = x - (int) sqrt(x) * 1ll * (int) sqrt(x);
  ll dw = abs(x - (int)(sqrt(x) + 1) * 1ll * (int)(sqrt(x) + 1));
  return min(dw, up);
}
void solve() {
  for(int i = 1; i <= 100000; i++)
    q[i][0] = 1;
  for(int i = 2; i <= 100000; i++) {
    for(int j = 1; j < 64; j++) {
      q[i][j] = q[i][j - 1] * i;
    }
  }
  cin >> n;
  vector<int> a(n);
  ll res = 0;
  rep(i, 0, n) {
    cin >> a[i];
    res += a[i] - 1;
  }
  sort(all(a));
  if (n < 3) {
    ll res = a[0] - 1;
    if (n > 1)
      res += f(a[1]);
    cout << res << endl;
    return;
  }
  for(int i = 2; ; i++) {
    if (can(a, i)) {
      res = min(res, calc(a, i));
    } else {
      break;
    }
  }
  cout << res << endl;
}
void prepare() {}
void stress() {}
void slow() {}
void _() {
//  isFile = 1;
}
int main() {
  faster();
  int t = 1;
//  cin >> t;
  int id = 1;
  while(t--) {
//    cout << "Case #" << id++ << ": ";
    solve();
//    prepare();
//    stress();
//    slow();
  }
  return 0;
}
