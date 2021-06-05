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
const int N = (int)4e5 + 5;
const int M = 1234;

ll f(ll x) {
    return x * (x + 1) / 2;
}

ull pref[N];
ull preh[N];
ull d[N];

ll get(int l, int r) {
    return pref[r] - pref[l - 1];
}

ll geth(int l, int r) {
    return preh[r] - preh[l - 1];
}

ll calc(ll l, ll r, ll x) {
    ll res = 0;
    ll need = x;
    res = geth(l + 1, r);
    need -= get(l + 1, r);
    res += f(d[l]) - (d[l] == need ? 0 : f(d[l] - need));
    return res;
}

void solve() {
    ll n, x;
    cin >> n >> x;
    ll s = 0;
    for(int i = 1; i <= n; i++) {
        cin >> d[i];
        d[i + n] = d[i];
    }

    for(int i = 1; i <= n + n; i++) {
        pref[i] = pref[i - 1] + d[i];
        preh[i] = preh[i - 1] + f(d[i]);
    }

    ll ans = 1;
    for(int i = 1; i <= n; i++) {
        ll l = i, r = n + n;
        while(r - l > 1) {
            ll m = (l + r) >> 1;
            if (get(i, m) < x) {
                l = m;
            } else {
                r = m;
            }
        }

        if (l <= n + n && get(i, l) < x)
            l++;

        if (get(i, l) < x || l == n + n + 1)
            skip;

        ans = max(ans, calc(i, l, x));
    }

    cout << ans << endl;
}

void _() {
}

int main() {
    faster();
    int t = 1;
//    cin >> t;
    while(t--) {
         solve();
    }
    return 0;
}
