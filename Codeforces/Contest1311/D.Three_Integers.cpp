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

vector<int> divs[20001];

pii calc(int a, int b) {
    int ep = inf;
    pii res = {1, 0};

    for(auto i : divs[a]) {
        if (abs(i - b) < ep) {
            ep = abs(i - b);
            res.fr = i;
        }
    }

    res.sc = ep;
    return res;
}

pii calc1(int a, int b) {
    if (b == 0)
    return {inf, inf};
    if (a - a / b * b <= (a / b + 1) * b - a) {
        return {a / b * b, a - a / b * b};
    } else {
        return {(a / b + 1) * b, a / b * b + b - a};
    }
}

vector<pair<int, vector<int>>> cases;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    // case 1
    if (b % a == 0 && c % b == 0) {
        cout << 0 << endl;
        cout << a << ' ' << b << ' ' << c << '\n';
        return;
    }

    int mn = inf;
    vi ans;


    for(int C = max(c - b, 1); C <= c + b; C++) {
        pii x = calc(C, b);
        int B = x.fr;
        if (B == 0)
            skip;
        int eps = x.sc;
        x = calc(B, a);
        eps += x.sc;
        int A = x.fr;
        if (mn > eps + abs(C - c)) {
            mn = eps + abs(C - c);
            ans = {A, B, C};
        }
    }

    for(int B = max(b - a, 1); B <= b + c; B++) {
        pii x = calc1(c, B);
        int C = x.fr;
        int eps = x.sc;
        x = calc(B, a);
        eps += x.sc;
        int A = x.fr;
        if (A == 0)
            skip;

        if (mn > eps + abs(b - B)) {
            mn = eps + abs(b - B);
            ans = {A, B, C};
        }
    }

    for(int A = 1; A <= a + b; A++) {
        pii x = calc1(b, A);
        int B = x.fr;
        if (B == 0)
            skip;

        int eps = x.sc;
        x = calc1(c, B);
        eps += x.sc;

        int C = x.fr;
        if (mn > eps + abs(a - A)) {
            mn = eps + abs(a - A);
            ans = {A, B, C};
        }
    }

    cout << mn << endl;
    for(auto i : ans) {
        cout << i << ' ';
    }
    cout << '\n';

    cases.clear();
}

int main() {
    faster();
    for(int i = 1; i <= 20000; i++) {
        for(int x = 1; x * x <= i; x++) {
            if (i % x == 0) {
                divs[i].pb(x);
                if (i / x != x) {
                    divs[i].pb(i / x);
                }
            }
        }
    }

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
