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
const int N = 3e5 + 5;
const int M = 1234;
set<char> q[N];
void solve() {
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; i++)
    q[i].clear();
  string s;
  cin >> s;
  for(int i = 0; i < n; i++) {
    if (s[i] != '?') {
      q[i % k].ins(s[i]);
      if (q[i % k].size() > 1) {
        cout << "NO\n";
        return;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    if (s[i] == '?') {
      if (q[i % k].empty()) {
        skip;
      }
      s[i] = *q[i % k].begin();
    }
  }
  vector<array<int, 3>> status;
  array<int, 3> cur = {0, 0, 0};
  for(int i = 0; i < k; i++) {
    if (s[i] == '1') {
      cur[1]++;
    } else
    if (s[i] == '0') {
      cur[0]++;
    } else {
      cur[2]++;
    }
  }
  status.pb(cur);
  for(int i = k; i < n; i++) {
    if (s[i - k] == '1') {
      cur[1]--;
    } else
    if (s[i - k] == '0') {
      cur[0]--;
    } else {
      cur[2]--;
    }
    if (s[i] == '1') {
      cur[1]++;
    } else
    if (s[i] == '0') {
      cur[0]++;
    } else {
      cur[2]++;
    }
    status.pb(cur);
  }
  k /= 2;
  for(int i = 0; i < sz(status); i++) {
    auto cur = status[i];
    if (cur[0] > k || cur[1] > k) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES" << endl;
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
//    cout << "Case #" << id++ << ": \n";
    solve();
//    prepare();
//    stress();
//    slow();
  }
  return 0;
}
