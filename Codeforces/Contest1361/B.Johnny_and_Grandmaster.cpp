#include <bits/stdc++.h>

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
const int N = (int)1e6 + 5;
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
} using namespace MATH_CAL;


int n, p;
map<int, int> cnt;
int k[N];

ll a, b;

void solve() {

    a = b = 0;

    cin >> n >> p;

    for(int i = 0; i < n; i++) {
        cin >> k[i];
    }

    if (p == 1) {
        cout << n % 2 << endl;
        return;
    }

    sort(k, k + n);
    reverse(k, k + n);

    int big = 0;
    bool flag = 0;

    for(int i = 0; i < n; i++) {
        if (!flag) {
            big = k[i];
            flag = 1;
            skip;
        }

        int who = k[i];
        cnt[who]++;

        while(cnt[who] == p) {
            cnt.erase(who);
            who++;
            cnt[who]++;
        }

        if (who == big) {
            cnt.clear();
            flag = 0;
        }
    }

    if (flag)
        a = qpow(p, big);

    for(auto &&[x, y] : cnt) {
        a = sub(a, mul(y, qpow(p, x)));
    }

    cout << a << endl;
    cnt.clear();
}

void _() {
//    isFile = 1;
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

// ???????? ?????????????? ????????????? ???????????? ?? ?????????????????????? ???????? ??????????????
// ???????????????? ???? long long
// ???????????????? ???? ?????????????? ??????????????
