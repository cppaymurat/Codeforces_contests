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
#define bpc(x) __builtin_popcountll(x)
#define rev(a) reverse(all(a))
#define skip continue
#define read(a) for(auto &i : a) cin >> i
#define print(a) for(auto i : a) cout << i << ' '
#define unique(a) sort(all(a));    a.resize(unique(all(a)) - a.begin())

//                D  R  U   L
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
const int MAXN = (int)1e3 + 5;
const int MOD = 998244353;
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

inline bool isPal(string x) {
    int n = (int)x.size();
    for(int i = 0; i < n / 2; i++) {
        if (x[i] != x[n - i - 1])
            return false;
    }
    return true;
}

inline bool isPal(string x, string y) {
    int n = (int)x.size();
    int m = (int)y.size();
    int l = 0, r = m - 1;
    while(l < n && r >= 0) {
        if (x[l] != y[r])
            return 0;
        l++;
        r--;
    }
    if (l == n && r == -1) {
        return 1;
    } else
    if (l == n) {
        l = 0;

        while(l < r) {
            if (y[l] != y[r]) {
                return 0;
            }
            l++;
            r--;
        }
        return 1;
    } else
    if (r == -1) {
        r = n - 1;
        while(l < r) {
            if (x[l] != x[r]) {
                return 0;
            }
            l++;
            r--;
        }
        return 1;
    }
    return 1;
}

void solve() {
    string t;
    cin >> t;

    if (isPal(t)) {
        cout << t << endl;
        return;
    }

    int n = (int)t.size();
    vector<string> pref(n), suff(n);
    pref[0] = t[0];
    suff[0] = t.back();

    for(int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + t[i];
    }

    int id = 1;
    for(int i = n - 2; i >= 0; i--) {
        suff[id] = t[i] + suff[id - 1];
        id++;
    }

    int mx = -1;
    string res = "", ans = "";
    for(int i = 0; i < n; i++) {
        if (isPal(pref[i])) {
            if (mx < (int)pref[i].size()) {
                mx = (int)pref[i].size();
                res = pref[i];
            }
        }
        if (isPal(suff[i])) {
            if (mx < (int)suff[i].size()) {
                mx = (int)suff[i].size();
                res = suff[i];
            }
        }
    }

    int l = 0, r = n - 1;
    string beg = "";
    while(l < r && t[l] == t[r]) {
        beg += t[l];
        l++;
        r--;
    }

    string s = "";
    for(int i = l; i <= r; i++)
        s += t[i];

    ans = beg;
    rev(beg);

    pref.clear();
    suff.clear();
    pref.pb("asd");
    pref[0] = s[0];
    suff.pb("hui");
    suff[0] = s.back();

    for(int i = 1; i < (int)s.size(); i++) {
        pref.pb(pref.back() + s[i]);
    }
    for(int i = (int)s.size() - 2; i >= 0; i--) {
        suff.pb(s[i] + suff.back());
    }

    mx = -1;
    string mid = "";
    for(auto i : pref) {
        if ((int)i.size() > mx && isPal(i)) {
            mx = (int)i.size();
            mid = i;
        }
    }
    for(auto i : suff) {
        if ((int)i.size() > mx && isPal(i)) {
            mx = (int)i.size();
            mid = i;
        }
    }
    ans += mid + beg;
    if (ans.size() > res.size()) {
        cout << ans << endl;
    } else
        cout << res << endl;
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
