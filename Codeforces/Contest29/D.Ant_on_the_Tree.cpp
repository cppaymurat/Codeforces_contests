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
vector<int> current_path;
int edge_used[M][M];
bool getPath(int from, int to, int pr = -1) {
  current_path.pb(from);
  for(int v : g[from]) {
    if (v == pr)
      skip;
    if (v == to) {
      current_path.pb(to);
      return true;
    }
    if (getPath(v, to, from)) {
      return true;
    }
  }
  current_path.pop_back();
  return false;
}
void solve() {
  int n;
  cin >> n;
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  vector<int> leafs = {1};
  map<int, bool> used_leaf;
  map<int, bool> is_leaf;
  int x;
  while(cin >> x) {
    leafs.pb(x);
    is_leaf[x] = 1;
  }
  leafs.pb(1);
  vector<int> result;
  for(int i = 0; i + 1 < sz(leafs); i++) {
    getPath(leafs[i], leafs[i + 1]);
    vector<int> path = current_path;
    for(int i = 0; i + 1 < sz(path); i++) {
      edge_used[path[i]][path[i + 1]]++;
      edge_used[path[i + 1]][path[i]]++;
      result.pb(path[i]);
      if (edge_used[path[i]][path[i + 1]] > 2 || edge_used[path[i + 1]][path[i]] > 2) {
        cout << -1 << endl;
        return;
      }
    }
    current_path.clear();
  }
  if (result.back() != 1)
    result.pb(1);
  for(int i = 0; i < sz(result); i++) {
    cout << result[i] << ' ';
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
