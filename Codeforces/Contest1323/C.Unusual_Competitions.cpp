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

int bal[MAXN];
int cntp[MAXN];
int cntn[MAXN];

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> good;
    good.pb(-1);
    for(int i = 0; i < s.size(); i++) {
        if (i > 0)
            bal[i] = bal[i - 1];
        if (s[i] == '(') {
            bal[i]++;
        } else {
            bal[i]--;
        }
        if (bal[i] < 0) {
            cntn[-bal[i]]++;
        } else {
            if (!bal[i]) {
                good.pb(i);
            }
            cntp[bal[i]]++;
        }
    }

    if (bal[n - 1]) {
        cout << -1 << endl;
        return;
    }

//    for(int i = 0; i < n; i++) {
//        cout << bal[i] << ' ';
//    }
//    cout << endl;

    int ans = 0;
    for(int i = 0; i < good.size() - 1; i++) {
        int lf = good[i], rg = good[i + 1];
       // cout << lf << ' ' << rg << '\n';
        int c = 0;
        bool ok = 1;
        for(int j = lf + 1; j < rg; j++) {
            if (bal[j] < 0) {
                ok = 0;
            }
            c++;
        }
        if (!ok)
            ans += c + 1;
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
