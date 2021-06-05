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
#define _all(v, x, n) v.begin() + x, v.begin() + n + x
#define unique(a) sort(all(a));    a.resize(unique(all(a)) - a.begin())
#define rev(a) reverse(all(a))

#define bit(n, i) (n >> i) & 1
#define bpc(x) __builtin_popcount(x)

const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isPrime(ll n) {    if (n < 2) return 0;    for(ll i = 2; i * i <= n; i++) {        if (n % i == 0) return 0;    }    return 1;}

ostream &operator<<(ostream &o, pii a) {
    o << "{" << a.fr << "," << a.sc << "}";
    return o;
}

istream &operator>>(istream &o, pii a) {
    o >> a.fr >> a.sc;
    return o;
}

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
const int MAXN = (int)2e5 + 5;
const int MOD = 998244353;
// 998244353
const ld  PI = acos(-1);
const ld  EPS = 3E-16;

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

int n, m, k;
int a[MAXN];
vector<int> g[MAXN];

vector<int> bfs(int start) {
    vector<int> d(MAXN, inf);
    queue<int> q;

    q.push(start);
    d[start] = 0;

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(auto to : g[v]) {
            if (d[to] > d[v] + 1) {
                d[to] = d[v] + 1;
                q.push(to);
            }
        }
    }

    return d;
}

void solve() {
    cin >> n >> m >> k;

    for(int i = 0; i < k; i++) {
        int t;
        cin >> t;
        a[t] = 1;
    }

    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    vector<int> x = bfs(1);
    vector<int> y = bfs(n);

    int mn = -1;

    vector<pair<pii, int>> dp;
    for(int i = 1; i <= n; i++) {
        if (a[i])
            dp.pb({{x[i], y[i]}, i});
    }

    sort(all(dp));

    ll ans = x[n];
    ll res = 0, mx = -1;

    for(int i = dp.size() - 1; i >= 0; i--) {
        if (mx != -1)
            res = max(res, mx + dp[i].fr.fr + 1);
        mx = max(mx, 1ll * dp[i].fr.sc);
    }

    cout << min(ans, res) << endl;
}

int main() {
    faster();
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
