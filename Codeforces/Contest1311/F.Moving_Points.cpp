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
#define lb lower_bound
#define ub upper_bound

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

ll cnt[MAXN];
ll xs[MAXN];

int sz1, sz2;

void upd(int pos, int val) {
    for(; pos < sz1; pos = (pos | (pos + 1))) {
        cnt[pos] += val;
    }
}

void upd1(int pos, int val) {
    for(; pos < sz2; pos = (pos | (pos + 1))) {
        xs[pos] += val;
    }
}

ll get(int pos) {
    ll res = 0;
    for(; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        res += cnt[pos];
    }
    return res;
}

ll get1(int pos) {
    ll res = 0;
    for(; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        res += xs[pos];
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vpii x(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i].fr;
    }
    for(int i = 0; i < n; i++) {
        cin >> x[i].sc;
    }
    sort(all(x));
    vector<int> v;
    for(auto i : x) {
        v.pb(i.sc);
    }
    unique(v);
    sz1 = v.size();
    sz2 = v.size();
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        x[i].sc = lower_bound(all(v), x[i].sc) - v.begin();
        ans += get(x[i].sc) * x[i].fr - get1(x[i].sc);
        upd(x[i].sc, 1);
        upd1(x[i].sc, x[i].fr);
    }

    cout << ans << endl;
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
