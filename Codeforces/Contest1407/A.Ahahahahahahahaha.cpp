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

#define debug(x) cerr << #x << "=" << x << endl
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
int ban[M];
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int s = 0;
  int sign = 1;
  int last = -1;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i] * sign;
    sign *= -1;
    if (s == 0) {
      last = i;
    }
  }
  for(int i = 0; i <= last; i++) ban[i] = 1;
  while(s != 0) {
    if (s > 0) {
      sign = 1;
      s = 0;
      for(int i = 0; i < n; i++) {
        if (!ban[i]) {
          if (a[i] && sign == 1) {
            ban[i] = 1;
            break;
          }
          sign *= -1;
        }
      }
      sign = 1;
      for(int i = 0; i < n; i++) {
        if (!ban[i]) {
          s += a[i] * sign;
          sign *= -1;
        }
      }
    } else {
      sign = 1;
      s = 0;
      for(int i = 0; i < n; i++) {
        if (!ban[i]) {
          if (a[i] && sign == -1) {
            ban[i] = 1;
            break;
          }
          sign *= -1;
        }
      }
      sign = 1;
      for(int i = 0; i < n; i++) {
        if (!ban[i]) {
          s += a[i] * sign;
          sign *= -1;
        }
      }
    }
  }
  int cnt = n;
  for(int i = last + 1; i < n; i++) {
    if (ban[i]) cnt--;
  }
  cout << cnt << endl;
  for(int i = 0; i < n; i++) {
    if (i <= last) {
      cout << a[i] << ' ';
      ban[i] = 0;
      skip;
    }
    if (!ban[i]) {
      cout << a[i] << ' ';
    }
    ban[i] = 0;
  }
  cout << endl;
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
  cin >> t;
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
