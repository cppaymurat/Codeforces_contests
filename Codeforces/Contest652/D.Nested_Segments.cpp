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

#define ins insert
#define all(v) v.begin(), v.end()
#define rep(i,a,n) for (int i=a;i<n;i++)
#define bit(n, i) (n >> i) & 1
#define bpc(x) __builtin_popcount(x)
#define rev(a) reverse(all(a))
#define skip continue
#define read(a) for(auto &i : a) cin >> i
#define print(a) for(auto i : a) cout << i << ' '
#define unique(a) sort(all(a));    a.resize(unique(all(a)) - a.begin())

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

int f[MAXN];
int n;

void upd(int pos, int val) {
    for(int i = pos; i < n; i = (i | (i + 1))) {
        f[i] += val;
    }
}

int get(int pos) {
    int res = 0;
    for(int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
        res += f[i];
    }
    return res;
}

void solve() {
    cin >> n;
    vector<int> lr, ans(n + 1, 0);
    vector<pair<pii, int>> seg(n);
    int id = 0;
    for(auto &u : seg) {
        cin >> u.fr.fr >> u.fr.sc;
        lr.pb(u.fr.sc);
        u.sc = id++;
    }

    unique(lr);
    sort(all(seg), [&](pair<pii, int> a, pair<pii, int> b) {
            if (a.fr.fr != b.fr.fr)
                return a.fr.fr > b.fr.fr;
            return a.fr.sc < b.fr.sc;
         });

    for(auto &u : seg) {
        u.fr.sc = lower_bound(all(lr), u.fr.sc) - lr.begin();
        ans[u.sc] = get(u.fr.sc);
        upd(u.fr.sc, 1);
    }

    for(int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
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
