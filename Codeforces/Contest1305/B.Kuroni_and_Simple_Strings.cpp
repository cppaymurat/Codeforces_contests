#include <bits/stdc++.h>
#define isFile 0
#define NAME "taskA"
#define scan 1
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<short, short> pss;
typedef pair<double, double> pdd;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pii> vpii;

#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define skip continue
#define ins insert
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define unique(a) sort(all(a));    a.resize(unique(all(a)) - a.begin())
#define rev(a) reverse(all(a))
#define lb lower_bound
#define ub upper_bound
#define rep(i,a,n) for (int i=a;i<n;i++)
#define read(a) for(auto &i : a) cin >> i
#define print(a) for(auto i : a) cout << i << ' '
#define bit(n, i) (n >> i) & 1
#define bpc(x) __builtin_popcount(x)

const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void faster() {
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

const ll  INF = 1e18;
const int inf = 2e9;
const int MAXN = (int)3e3 + 5;
const int MOD = 998244353;
// 998244353
const ld  PI = acos(-1);
const ld  EPS = 3E-16;
const int ALPHA = 26;

namespace MATH_CAL {
    const int mod = MOD;
    inline ll add(ll a, ll b) { return a + b >= mod ? a + b - mod : a + b; }
    inline ll sub(ll a, ll b) { return a - b < 0 ? a - b + mod : a - b; }
    inline ll mul(ll a, ll b) { return (ll) a * b % mod; }
    inline void Add(ll &a, ll b) { (a += b) >= mod ? a -= mod : 0; }
    inline void Sub(ll &a, ll b) { (a -= b) < 0 ? a += mod : 0; }
    inline ll qpow(ll x, ll n) { ll r = 1; for ( ; n; n /= 2, x = mul(x, x)) if (n & 1) r = mul(r, x); return r; }
    inline ll mod_inv(ll x) { return qpow(x, mod - 2); }
    inline ll gcd(ll a, ll b) {while(b) {a %= b; swap(a, b);} return a;}
} using namespace MATH_CAL;

vector<vector<int>> ans;

bool anyOp(string s) {
    bool op = 0, cl = 0;
    for(auto i : s) {
        if (i == '(') {
            op = 1;
        } else
        {
            if (op == 1) {
                return true;
            }
        }
    }
    return false;
}

string parse(string s) {
    vector<pii> st;
    int n = s.size();
    vector<int> op(n, 0), cl(n, 0);
    op[0] = cl[0] = 0;
    for(int i = 0; i < s.length(); i++) {
        if (i > 0)
            op[i] = op[i - 1];
        if (s[i] == '(') {
            op[i]++;
        }
    }

    for(int i = s.size() - 1; i >= 0; i--) {
        if (i != s.size() - 1) {
            cl[i] = cl[i + 1];
        }
        if (s[i] == ')') {
            cl[i]++;
        }
    }

    int id = -1;
    int mx = -1;
    for(int i = 0; i < n; i++) {
//        cout << op[i] << ' ' << cl[i] << '\n';
        if (min(op[i], cl[i]) > mx) {
            mx = min(op[i], cl[i]);
            id = i;
        }
    }

    vector<int> cur;
    int need = mx;
    vector<int> bad(n + 1, 0);
    for(int i = 0; i <= id; i++) {
        if (s[i] == '(' && need) {
            need--;
            cur.pb(i + 1);
            bad[i] = 1;
        }
    }
    need = mx;
    for(int i = n - 1; i >= id; i--) {
        if (s[i] == ')' && need) {
            need--;
            bad[i] = 1;
            cur.pb(i + 1);
        }
    }
    sort(all(cur));
    ans.pb(cur);
    string now = "";
    for(int i = 0; i < n; i++) {
        if (!bad[i])
            now += s[i];
    }
    return now;
}

void solve() {
    string s;
    cin >> s;
    while(anyOp(s)) {
        s = parse(s);
    }

    cout << ans.size() << endl;
    for(auto i : ans) {
        cout << i.size() << '\n';
        for(auto j : i) {
            cout << j << ' ';
        }
        cout << '\n';
    }

}

int main() {
    faster();
    int t = 1;
//    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
