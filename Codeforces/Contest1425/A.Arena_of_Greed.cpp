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
void solve() {
  ll n;
  cin >> n;
  ll a = 0, b = 0;
  bool turn = 1;
  while(n > 0) {
    if (turn) {
      if (n % 2 == 0) {
        if (n / 2 % 2 == 0 && n / 4 != 1) {
          a++;
          n--;
        } else {
          a += n / 2;
          n /= 2;
        }
      } else {
        a++;
        n--;
      }
    } else {
      if (n % 2 == 0) {
        if (n / 2 % 2 == 0 && n / 4 != 1) {
          b++;
          n--;
        } else {
          b += n >> 1;
          n >>= 1;
        }
      } else {
        b++;
        n--;
      }
    }
    turn ^= 1;
  }
  cout << a << endl;
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
