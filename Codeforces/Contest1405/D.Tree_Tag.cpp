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
vector<int> g[N];
int d[N];
void dfs(int v, int pr = -1, int lvl = 0) {
  d[v] = lvl++;
  for(int to : g[v]) {
    if (to != pr)
      dfs(to, v, lvl);
  }
}
void solve() {
  int n, a, b, da, db;
  cin >> n >> a >> b >> da >> db;
  for(int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  dfs(a);
  int id = -1, mx = -1;
  for(int i = 1; i <= n; i++) {
    if (d[i] > mx) {
      mx = d[i];
      id = i;
    }
  }
  int to_b = d[b];
  dfs(id);
  for(int i = 1; i <= n; i++) {
    if (d[i] > mx) {
      mx = d[i];
    }
  }
  db = min(db, mx);
  da = min(da, mx);
  if (to_b <= da) {
    cout << "Alice" << endl;
  } else
  if (db > da * 2) {
    cout << "Bob" << endl;
  } else {
    cout << "Alice" << endl;
  }
  for(int i = 1; i <= n; i++) {
    g[i].clear();
  }
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

