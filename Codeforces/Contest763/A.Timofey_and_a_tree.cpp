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
#define x fr
#define y sc
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

pair<pii, pii> intersect(pii f1, pii f2, pii s1, pii s2) {    int x5, y5, x6, y6;    x5 = max(min(f1.x, f2.x), min(s1.x, s2.x));    x6 = min(max(f1.x, f2.x), max(s1.x, s2.x));    y5 = max(min(f1.y, f2.y), min(s1.y, s2.y));    y6 = min(max(f1.y, f2.y), max(s1.y, s2.y));    if (x5 >= x6 || y5 >= y6) {        return {{0, 0}, {0, 0}};    }    return {{x5, y5}, {x6, y6}};}

bool isPrime(ll n) {    if (n < 2) return 0;    for(ll i = 2; i * i <= n; i++) {        if (n % i == 0) return 0;    }    return 1;}

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
const int inf = 1e9;
const int MAXN = (int)1e5 + 123;
const int MOD = (int)1e9 + 7;
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

vector <int> g[MAXN];
int col[MAXN];
vector <pii> edge;
set <int> dif;

void dfs(int v, int pr) {
    dif.ins(col[v]);
    for(auto to : g[v]) {
        if (to != pr) {
            dfs(to, v);
        }
    }
}

bool check(int v) {
    for(auto to : g[v]) {
        dif.clear();
        dfs(to, v);
        if (dif.size() > 1)
            return 0;
    }
    return 1;
}

void solve() {

    int n;
    cin >> n;

    for(int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        if (u > v) swap(u, v);
        edge.pb({u, v});
    }

    for(int i = 1; i <= n; i++) {
        cin >> col[i];
    }

    bool ok = 0;
    for(auto e : edge) {
        int u = e.fr;
        int v = e.sc;
        if (col[u] != col[v]) {
            if (check(u)) {
                cout << "YES\n";
                cout << u << '\n';
                return;
            }
            if (check(v)) {
                cout << "YES\n";
                cout << v << '\n';
                return;
            }
            ok = 1;
            break;
        }
    }

    if (!ok) {
        cout << "YES\n1\n";
        return;
    }

    cout << "NO\n";
}

int main() {
    faster();
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
