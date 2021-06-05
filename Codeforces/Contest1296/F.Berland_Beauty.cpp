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
const int MAXN = (int)5e3 + 5;
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

int n;
vector<int> g[MAXN];
vector<pii> edge(MAXN);
int ans[MAXN];
vector<int> path[5001];
int id;
bool dfs3(int v, int p, int f){

	path[id].pb(v);
	if(v == f)
		return 1;

	for(int to : g[v])
		if(to != p)
			if(dfs3(to, v, f))
				return 1;

    path[id].pop_back();
	return 0;
}

int ed[MAXN][MAXN];
void solve() {
    cin >> n;

    for(int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        ed[u][v] = ed[v][u] = i;
    }

    int m;
    cin >> m;

    vector<int> qx, qy, qz;
    for(int i = 1; i <= m; i++) {
        id = i;
        int u, v, f;
        cin >> u >> v >> f;
        qx.pb(u);
        qy.pb(v);
        qz.pb(f);
        dfs3(u, -1, v);
        for(int j = 0; j < path[id].size() - 1; j++) {
            int x = path[id][j];
            int y = path[id][j + 1];
            ans[ed[x][y]] = max(ans[ed[x][y]], f);
        }
    }

    for(int i = 0; i < m; i++) {
        int u = qx[i];
        int v = qy[i];
        int f = qz[i];
        int mn = inf;
        for(int j = 0; j < path[i + 1].size() - 1; j++) {
            int x = path[i + 1][j];
            int y = path[i + 1][j + 1];
            mn = min(mn, ans[ed[x][y]]);
        }
        if (mn > f) {
            cout << -1 << endl;
            return;
        }
    }

    for(int i = 1; i <= n - 1; i++) {
        if (ans[i] == 0) ans[i] = 1e6;
        cout << ans[i] << " ";
    }
    cout << endl;
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
