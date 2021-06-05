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
int f(const string& s) {
  int res = 0;
  for(char c : s)
    res += c - '0';
  return res;
}
ll calc(string n, int s) {
  ll ans = 0;
  rev(n);
  ll cur = f(n);
  ll q = 1;
  for(int i = 0; i < sz(n) - 1; q *= 10, i++) {
    ll dif = n[i] - '0';
    if (!dif)
      skip;
    ans += q * (10 - dif);
    if (n[i + 1] < '9') {
      n[i + 1]++;
      dif--;
    } else {
      dif += 9;
      n[i + 1] = '0';
      int id = i + 2;
      while(n[id] == '9') {
        n[id] = '0';
        dif += 9;
        id++;
      }
      n[id]++;
      dif--;
    }
    cur -= dif;
    if (cur <= s)
      break;
  }
  return ans;
}
void solve() {
  string n;
  int s;
  cin >> n >> s;
  for(int i = 0; i <= 100; i++)
    n = "0" + n;
  if (f(n) <= s) {
    cout << 0 << endl;
    return;
  }
  cout << calc(n, s) << endl;
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
