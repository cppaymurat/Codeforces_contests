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
const int N = 1e5 + 5;
const int M = 1234;
int cnt[N];
void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  int delta = 0;
  int ok = 0;
  int was = 0;
  set<int> s;
  ll sum = 0;
  rep(i, 0, n) {
    cin >> a[i];
    sum += a[i];
    if (a[i] != x) ok++;
    if (a[i] == x) was++;
    delta += a[i] - x;
    s.ins(a[i] - x);
  }
  if (delta == 0 && ok == 0) {
    cout << 0 << endl;
    return;
  }
  if (sum % n == 0 && sum / n == x) {
    cout << 1 << endl;
    return;
  }
  if (was) {
    cout << 1 << endl;
    return;
  }
  cout << 2 << endl;
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
