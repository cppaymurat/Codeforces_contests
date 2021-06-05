#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

typedef pair<int, int> pii;
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
#define _all(v, x, n) v.begin() + x, v.begin() + n + x
#define unique(a) sort(all(a));    a.resize(unique(all(a)) - a.begin())

#define bit(n, i) (n >> i) & 1
#define bpc(x) __builtin_popcount(x)
#define NAME "taskA"
#define scan 1
#define isFile 0

int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

template<class T, class V>
int min(T a, V b) {
    return min((int)a, (int)b);
}

template<class T, class V>
int max(T a, V b) {
    return max((int)a, (int)b);
}


bool isPrime(ll n, ll p) {
    if (n < 2) return 0;
    for(ll i = 2; i * i <= n; i++) {
        if (i > p) break;
        if (n % i == 0) return 0;
    }

    return 1;
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

const ll INF = 1e18;
const int MAXN = (int)2e5 + 123;
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

void solve(){

    int n;
    cin >> n;
    vi a(n);
    vi pref(n + 2, 0);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i] = pref[max(i - 1, 0)] + a[i];
    }

    pref[n] = pref[n - 1];
    pref[n + 1] = pref[n];

    int q;
    cin >> q;

    while(q--) {
        int x;
        cin >> x;
        int l = 0, r = n - 1;
        bool ok = 0;
        while(r - l > 1) {
            int m = (r + l) >> 1;
            if (pref[m] > x) {
                r = m;
            } else
            if (pref[m] < x) {
                l = m;
            } else {
                ok = 1;
                cout << m + 1 << endl;
                break;
            }
        }
        if (!ok) {
            if (pref[l] >= x) {
                cout << l + 1 << endl;
            } else
            cout << l + 2 << endl;
          //  cout << pref[l + 2] << endl;
        }
    }

}

int main() {
    faster();
    int t = 1;
 //   cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}