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
const int MAXN = (int)2e5 + 5;
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

int n, m;
vector<int> g[MAXN];
vector<int> p(MAXN);
vector<int> d(MAXN);
int cnt[MAXN];

void bfs(int st) {
    rep(i, 1, n + 1) {
        d[i] = inf;
    }
    queue<int> q;
    q.push(st);
    d[st] = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(auto to : g[v]) {
            if (d[to] > d[v] + 1) {
                d[to] = d[v] + 1;
                q.push(to);
                cnt[to] = 1;
            } else
            if (d[to] == d[v] + 1) {
                cnt[to]++;
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        g[v].pb(u);
    }

    int k;
    cin >> k;
    rep(i, 0, k) {
        cin >> p[i];
    }

    bfs(p[k - 1]);

//    rep(i, 0, k) {
//        cout << d[p[i]] << ' ';
//    }
//    cout << '\n';

    int mn = 0, mx = 0;
    rep(i, 0, k - 1) {
        if (d[p[i]] != d[p[i + 1]] + 1) {
            mn++;
            mx++;
        }
        if (d[p[i]] == d[p[i + 1]] + 1 && cnt[p[i]] != 1)
            mx++;
    }

    cout << mn << ' ' << mx << '\n';
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
