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

void solve() {
    int a, b, p;
    cin >> a >> b >> p;

    string s;
    cin >> s;

    vector<pair<int, int>> go;
    int cur = 0;
    char x = s[0];

    for(int i = 0; i < s.size(); i++) {
        if (s[i] == x) {
            cur++;
        }
        if (s[i] != x || i == s.size() - 1) {
            go.pb({cur, x - 'A' + 1});
            if (i == s.size() - 1) {
                if (s[i] == x) {
                    go.back().fr--;
                }
            }
            cur = 1;
            x = s[i];
        }
    }

    vector<ll> pref, walk;
    map<int, int> cost;
    cost[1] = a;
    cost[2] = b;
    pref.pb(0);
    walk.pb(0);
    for(auto i : go) {
        pref.pb(pref.back() + cost[i.sc]);
        walk.pb(walk.back() + i.fr);
    }

    for(int i = 0; i < pref.size(); i++) {
        if (pref.back() - pref[i] <= p) {
            cout << walk[i] + 1 << endl;
            return;
        }
    }
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
