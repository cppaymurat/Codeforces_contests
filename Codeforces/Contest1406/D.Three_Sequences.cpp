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
ll sum;
void apply(vector<ll>& b, vector<ll>& a, int l, int r, const int& x) {
  l--, r--;
  if (l > 0) {
    sum -= max(0ll, b[l - 1]);
    b[l - 1] += x;
    sum += max(0ll, b[l - 1]);
  } else {
    a[l] += x;
  }
  if (r < sz(b)) {
    sum -= max(0ll, b[r]);
    b[r] -= x;
    sum += max(0ll, b[r]);
  }
}
void calc(vector<ll>& a) {
  if (ceil((a[0] * 1.0 + sum) / 2) == 0)
    cout << 0 << endl;
  else
    cout << (ll) ceil((a[0] * 1.0 + sum) / 2) << endl;
}
void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n - 1);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if (i > 0) {
      b[i - 1] = a[i] - a[i - 1];
      sum += max(0ll, b[i - 1]);
    }
  }
  calc(a);
  int q;
  cin >> q;
  while(q--) {
    int l, r, x;
    cin >> l >> r >> x;
    apply(b, a, l, r, x);
    calc(a);
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
