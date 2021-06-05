#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;

#define NAME "taskA"
#define scan 1
bool isFile;
using namespace std;


typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

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
#define onbit(x, i) (x | (1ll << (i - 1)))
#define offbit(x, i) (x & ~(1ll << (i - 1)))
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

void _();

void faster() {
    _();
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

const ll  INF = 9e18;
const int inf = 2e9;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const ld  PI = acos(-1);
const ld  EPS = 3E-16;
const int ALPHA = 27;
const int N = (int)1e5 + 5;
const int M = 1234;

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
    inline ll lcm(ll a, ll b) {return a * b / gcd(a, b);}
    inline bool isPrime(ll a) {if (a < 2) return 0; for(ll i = 2; i * i <= a; i++) { if (a % i == 0)return 0;}return 1;}
} using namespace MATH_CAL;

int cx[11];

bool check(string t, vector<string> s, int n, int m) {
    for(int i = 0; i <= 10; i++)
        cx[i] = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
//            cout << s[j][i] << endl;
//            cout << t[i] << endl;
            if (s[j][i] != t[i]) {
                cx[j]++;
//                cout << cx[j] << endl;
                if (cx[j] > 1) {
                    return false;
                }
            }
        }
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    set<char> cnt[11];
    vector<string> s(n);

    for(int i = 0; i < n; i++) {
        cin >> s[i];
        for(int j = 0; j < m ; j++) {
            cnt[j].insert(s[i][j]);
        }
    }

    int d = 0;
    for(int i = 0; i < m; i++) {
        if (cnt[i].size() > 3)
            d++;
    }

    if (d > 3) {
        cout << -1 << endl;
        return;
    }

    for(auto a : cnt[0]) {
        if (m > 1) {
            for(auto b : cnt[1]) {
                if (m > 2) {
                    for(auto c : cnt[2]) {
                        if (m > 3) {
                            for(auto d : cnt[3]) {
                                if (m > 4) {
                                    for(auto e : cnt[4]) {
                                        if (m > 5) {
                                            for(auto f : cnt[5]) {
                                                if (m > 6) {
                                                    for(auto g : cnt[6]) {
                                                        if (m > 7) {
                                                            for(auto h : cnt[7]) {
                                                                if (m > 8) {
                                                                    for(auto i : cnt[8]) {
                                                                        if (m > 9) {
                                                                            for(auto k : cnt[9]) {
                                                                                string t = "";
                                                                                t += a;
                                                                                t += b;
                                                                                t += c;
                                                                                t += d;
                                                                                t += e;
                                                                                t += f;
                                                                                t += g;
                                                                                t += h;
                                                                                t += i;
                                                                                t += k;
                                                                                if (check(t, s, n, m)) {
                                                                                    cout << t << endl;
                                                                                    return;
                                                                                }
                                                                            }
                                                                        } else {
 string t = "";
                                    t += a;
                                    t += b;
                                    t += c;
                                    t += d;
                                    t += e;
                                    t += f;
                                    t += g;
                                    t += h;
                                    t += i;
                                                                            if (check(t , s, n, m)) {
                                                                                cout << t << endl;
                                                                                return;
                                                                            }
                                                                        }
                                                                    }
                                                                } else {
                                                                    string t = "";
                                    t += a;
                                    t += b;
                                    t += c;
                                    t += d;
                                    t += e;
                                    t += f;
                                    t += g;
                                    t += h;
                                                                    if (check(t , s, n, m)) {
                                                                        cout << t << endl;
                                                                        return;
                                                                    }
                                                                }
                                                            }
                                                        } else {
                                                                     string t = "";
                                    t += a;
                                    t += b;
                                    t += c;
                                    t += d;
                                    t += e;
                                    t += f;
                                    t += g;
                                                            if (check(t , s, n, m)) {
                                                                cout << t << endl;
                                                                return;
                                                            }
                                                        }
                                                    }
                                                }else {
                                                    string t = "";
                                    t += a;
                                    t += b;
                                    t += c;
                                    t += d;
                                    t += e;
                                    t += f;
                                                    if (check(t , s, n, m)) {
                                                        cout << t << endl;
                                                        return;
                                                    }
                                                }
                                            }
                                        }else {
                                            string t = "";
                                    t += a;
                                    t += b;
                                    t += c;
                                    t += d;
                                    t += e;
                                        if (check(t , s, n, m)) {
                                            cout << t << endl;
                                            return;
                                        }
                                    }
                                    }
                                }else {
                                    string t = "";
                                    t += a;
                                    t += b;
                                    t += c;
                                    t += d;
//                                    cout << t << endl;
                                        if (check(t, s, n, m)) {
                                            cout << t << endl;
                                            return;
                                        }
                                    }
                            }
                        }else {
                            string t = "";
                                    t += a;
                                    t += b;
                                    t += c;
                                        if (check(t, s, n, m)) {
                                            cout <<t << endl;
                                            return;
                                        }
                                    }
                    }
                }else {
                    string t = "";
                                    t += a;
                                    t += b;
                                        if (check(t , s, n, m)) {
                                            cout << t << endl;
                                            return;
                                        }
                                    }
            }
        }else {
            string t = "";
                                    t += a;
                                        if (check(t , s, n, m)) {
                                            cout << t << endl;
                                            return;
                                        }
                                    }
    }
    cout << -1 << endl;
}

void _() {
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
