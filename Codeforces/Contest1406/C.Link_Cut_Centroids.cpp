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
vector<int> g[N];
int child[N];
int most;
vector<int> centroids;
void dfs(int v, int pr = -1) {
  for(int to : g[v]) {
    if (to != pr) {
      dfs(to, v);
      child[v] += child[to];
    }
  }
  child[v]++;
}
void kfc(int v, int pr = -1) {
  bool ok = 1;
  for(int to : g[v]) {
    if (to != pr) {
      kfc(to, v);
      if (child[to] > most / 2)
        ok = 0;
    }
  }
  if (most - child[v] > most / 2)
    ok = 0;
  if (ok)
    centroids.pb(v);
}
void solve() {
  int n;
  cin >> n;
  pair<int, int> any_edge;
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
    any_edge = {u, v};
  }
  dfs(1);
  most = child[1];
  kfc(1);
  if (sz(centroids) == 1) {
    cout << any_edge.fr << ' ' << any_edge.sc << '\n';
    cout << any_edge.fr << ' ' << any_edge.sc << '\n';
  } else {
    int u = centroids[0];
    int v = centroids[1];
    int p, q;
    for(int to : g[u]) {
      if (to != v)
        p = to;
    }
    cout << u << ' ' << p << '\n';
    cout << v << ' ' << p << '\n';
  }
  for(int i = 1; i <= n; i++) {
    g[i].clear();
    child[i] = 0;
  }
  centroids.clear();
  most = 0;
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
//    cout << "Case #" << id++ << ": " << endl;
    solve();
//    prepare();
//    stress();
//    slow();
  }
  return 0;
}
