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
#define bit(x, i) (x >> (i - 1) & 1ll)
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

const ll  INF = 1e18;
const int inf = 2e9;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const ld  PI = acos(-1);
const ld  EPS = 3E-16;
const int ALPHA = 27;
const int N = (int)1e5 + 5;
const int M = 1234;

vector<int> g[N];
bool isLeaf[N];
int lvl[N];
int res;

void dfs(int v, int pr = -1) {
    for(auto to : g[v]) {
        if (to != pr) {
            lvl[to] = lvl[v] + 1;
            dfs(to, v);
        }
    }
}

void dfs2(int v, int pr = -1) {
    int cur = 0;
    for(auto to : g[v]) {
        if (to != pr && isLeaf[to]) {
            cur++;
        }
    }

    if (cur) {
        res += cur - 1;
    }

    for(auto to : g[v]) {
        if (to != pr) {
            dfs2(to, v);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    vector<int> leaf;
    int root = -1;
    for(int i = 1; i <= n; i++) {
//        d[i] = inf;
        if ((int) g[i].size() == 1) {
            leaf.pb(i);
            isLeaf[i] = 1;
        } else {
            root = i;
        }
    }

    lvl[root] = 1;
    dfs(root);

    int even = 0;
    for(auto i : leaf) {
        if (lvl[i] % 2 == 0) {
            even++;
        }
    }

    int odd = (int) leaf.size() - even;

    int min_ans = 1;
    if (odd == 0) {
        min_ans = 1;
    } else
    if (even) {
        min_ans = 3;
    }

    dfs2(root);

    cout << min_ans << ' ' << n - 1 - res << endl;
}

void _() {
    isFile = 0;
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
