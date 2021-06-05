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
const int N = (int)2e5 + 5;
const int M = 1234;

int a[N], b[N], c[N];
vector<int> g[N];
ll res = 0;

void dfs(int v, int pr) {
    for(auto to : g[v]) {
        if (to != pr) {
            a[to] = min(a[to], a[v]);
            dfs(to, v);
        }
    }
}

pair<ll, ll> dfs1(int v, int pr) {
    pair<ll, ll> cur = {0, 0};

    if (b[v] != c[v]) {
        cur.fr += b[v];
        cur.sc += c[v];
    }

    for(auto to : g[v]) {
        if (to != pr) {
            pair<ll, ll> child = dfs1(to, v);
            cur.fr += child.fr;
            cur.sc += child.sc;
        }
    }

    ll del = min(cur.fr, cur.sc);

    res += del * a[v];

    cur.fr -= del;
    cur.sc -= del;

    return cur;
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    for(int i = 1; i <= n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, -1);
    auto x = dfs1(1, -1);
    if (x.fr || x.sc)
        cout << -1 << endl;
    else
        cout << res + res << endl;
}

void _() {
//    isFile = 1;
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

// Слоу пишется быстро? Напиши и протестируй свое решение
// Посмотри на long long
// Посмотри на размеры массива
