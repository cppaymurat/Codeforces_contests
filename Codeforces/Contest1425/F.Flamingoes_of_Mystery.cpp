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
const int N = 1e3 + 5;
const int M = 1234;
int a[N];
int s[N];
int ask(int i, int j) {
  cout << "? " << i << ' ' << j << endl;
  fflush(stdout);
  int sum;
  cin >> sum;
  return sum;
}
void solve() {
  int n;
  cin >> n;
  int last = -1;
  for(int i = 1; i + 2 <= n; i += 3) {
    int x = ask(i, i + 1);
    int y = ask(i + 1, i + 2);
    int z = ask(i, i + 2);
    a[i + 1] = x + y - z;
    a[i] = x - a[i + 1];
    a[i + 2] = y - a[i + 1];
    last = i + 3;
  }
  vector<int> pref(n + 1);
  pref[1] = a[1];
  for(int i = 2; i < last; i++) {
    pref[i] = pref[i - 1] + a[i];
  }
  for(int i = last; i <= n; i++) {
    int x = ask(1, i);
    a[i] = x - pref[i - 1];
    pref[i] = pref[i - 1] + a[i];
  }
  cout << "! ";
  for(int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  cout << endl;
  fflush(stdout);
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
