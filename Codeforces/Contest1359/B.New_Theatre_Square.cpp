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

int a[105][1005];
ll n, m, x, y;

ll f(ll p) {
    if (p < 2) {
        return x * p;
    }
    ll b2 = p / 2;

    if (x + x > y) {
        return b2 * y + (p - b2 * 2) * x;
    }

    return x * p;
}

ll calc(int row) {
    int len = 0;
    ll res = 0;
    for(int i = 1; i <= m; i++) {
        if (a[row][i] == 1) {
            len++;
        } else {
            res += f(len);
            len = 0;
        }
    }

    if (len > 0)
        res += f(len);

    return res;
}

void solve() {
    cin >> n >> m >> x >> y;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if (c == '.') {
                a[i][j] = 1;
            } else {
                a[i][j] = 0;
            }
        }
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += calc(i);
    }

    cout << ans << endl;
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
