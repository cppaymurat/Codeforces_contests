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
bool prime[N];
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> p;
  int m = n;
  for(int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      int k = 0;
      while(n % i == 0) {
        n /= i;
        k++;
      }
      p.pb({i, k});
    }
  }
  if (n > 1) {
    p.pb({n, 1});
  }
  n = m;
  vector<int> divs;
  for(int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      divs.pb(i);
      if (i != n / i) {
        divs.pb(n / i);
      }
    }
  }
  divs.pb(n);
  map<int, bool> pairs;
  map<int, int> mark;
  if (sz(p) == 2 && p[0].sc == 1 && p[1].sc == 1) {
    cout << p[0].fr << ' ' << p[0].fr * p[1].fr << ' ' << p[1].fr << '\n';
    cout << 1 << endl;
    return;
  }
  if (sz(p) == 2) {
    for(int x : divs) {
      if (x != n && x != p[0].fr && x % p[0].fr == 0 && x != p[0].fr * p[1].fr) {
        cout << x << ' ';
        mark[x] = 1;
      }
    }
    mark[p[0].fr] = mark[p[0].fr * p[1].fr] = mark[p[1].fr] = 1;
    cout << p[0].fr << ' ' << p[0].fr * p[1].fr << ' ' << p[1].fr << ' ';
    for(int x : divs) {
      if (x != n && x % p[1].fr == 0 && !mark.count(x)) {
        cout << x << ' ';
      }
    }
    cout << n << endl;
    cout << 0 << endl;
    return;
  }
  sort(all(p));
  p.pb(p[0]);
  for(int i = 0; i + 1 < sz(p); i++) {
    pairs[p[i].fr * p[i + 1].fr] = 1;
  }
  vector<int> res;
  for(int i = 0; i + 1 < sz(p); i++) {
    int u = p[i].fr;
    int v = p[i + 1].fr;
    if (!mark.count(u)) {
      res.pb(u);
      mark[u] = 1;
    }
    for(int j = 0; j < sz(divs); j++) {
      if (v != divs[j] && divs[j] % u == 0 && !pairs.count(divs[j]) && !mark.count(divs[j])) {
        mark[divs[j]] = 1;
        res.pb(divs[j]);
      }
    }
    if (!mark.count(u * v)) {
      res.pb(u * v);
      mark[u * v] = 1;
    }
    if (!mark.count(v)) {
      res.pb(v);
      mark[v] = 1;
    }
  }
  for(int x : res) {
    cout << x << ' ';
  }
  cout << endl;
  cout << 0 << endl;
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
