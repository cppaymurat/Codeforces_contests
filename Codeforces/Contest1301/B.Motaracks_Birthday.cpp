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

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m = 0;

    vector<int> nb;
    for(int i = 1; i < n - 1; i++) {
        if (a[i] != -1 && (a[i - 1] == -1 || a[i + 1] == -1)) {
            nb.pb(a[i]);
        }
    }

    if (a[n - 1] != -1 && a[n - 2] == -1) nb.pb(a[n - 1]);
    if (a[0] != -1 && a[1] == -1) nb.pb(a[0]);

    if (nb.empty()) {
        cout << 0 << ' ' << 0 << endl;
        return;
    }

    sort(all(nb));
    int k = (nb[0] + nb.back()) >> 1;
    for(int i = 0; i < n; i++) {
        if (a[i] == -1) {
            a[i] = k;
        }
    }

    for(int i = 0; i < n - 1; i++) {
        m = max(m, abs(a[i] - a[i + 1]));
    }

    cout << m << ' ' << k << endl;
}

int main() {
    faster();
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
