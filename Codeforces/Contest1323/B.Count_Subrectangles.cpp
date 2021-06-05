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
#define unique(a) sort(all(a));    a.resize(unique(all(a)) - a.begin())
#define rev(a) reverse(all(a))
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
const int MAXN = (int)1e6 + 5;
const int MOD = 1e9 + 7;
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

ll n, m, k;
vector<ll> divs;
ll calc(ll a, ll b) {
    ll res = 0;
    for(auto x : divs) {
        ll F = x;
        ll S = k / x;
        if (a < F || b < S)
            skip;
        res += (a - F + 1) * (b - S + 1);
    }
    return res;
}

void solve() {
    cin >> n >> m >> k;
    ll ans = 0;
    vector<ll> blocks_a;
    vector<ll> blocks_b;
    ll cnt = 0;
    ll cur = 1;
    vi a(n), b(m);

    for(ll i = 1; i * i <= k; i++) {
        if (k % i == 0) {
            divs.pb(i);
            if (k / i != i)
                divs.pb(k / i);
        }
    }

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    for(int i = 0; i < n; i++) {
        if (a[i] == cur) {
            cnt++;
        }
        if (a[i] != cur || i == n - 1) {
            if (cnt) {
                blocks_a.pb(cnt);
                cnt = 0;
            }
        }
    }

    for(int i = 0; i < m; i++) {
        if (b[i] == cur) {
            cnt++;
        }
        if (b[i] != cur || i == m - 1) {
            if (cnt) {
                blocks_b.pb(cnt);
                cnt = 0;
            }
        }
    }

    if (blocks_a.size() * blocks_b.size() == 0ll) {
        cout << 0 << endl;
        return;
    }

    map<int, int> cnt_a, cnt_b;
    for(auto i : blocks_a)
        cnt_a[i]++;
    for(auto i : blocks_b)
        cnt_b[i]++;

    for(auto i : cnt_a) {
        for(auto j : cnt_b) {
            ans += calc(i.fr, j.fr) * i.sc * j.sc;
        }
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
