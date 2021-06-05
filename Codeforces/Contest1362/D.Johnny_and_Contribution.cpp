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
const int N = (int)5e5 + 5;
const int M = 1234;

vector<int> g[N];
vector<int> c[N];
int col[N];
vector<int> ans;
int n, m;

void dfs(int v, int cur) {
    int mx = 0;
    vector<int> s;
    for(auto to : g[v]) {
        if (col[to] > 0) {
            s.pb(col[to]);
            if (col[to] == cur) {
                cout << -1 << endl;
                exit(0);
            }
        }
    }

    unique(s);

    if (s.empty()) {
        ans.pb(v);
        col[v] = cur;
    } else {
        int mn = n;
        if (s[0] != 1) {
            cout << -1 << endl;
            exit(0);
        }
        if (s.size() == 1) {
            if (s[0] > cur || (cur == s[0] + 1 && s[0] == 1)) {
                ans.pb(v);
                col[v] = cur;
            } else
            if (s[0] == cur || cur - s[0] > 1) {
                cout << -1 << endl;
                exit(0);
            }
        } else {
            if (cur == 1 && s[0] != 1) {
                ans.pb(v);
                col[v] = cur;
            } else
            if (cur != 1 && s[0] != 1) {
                cout << -1 << endl;
                exit(0);
            } else {
                int mex = inf;
                for(int i = 1; i < s.size(); i++) {
                    if (s[i - 1] + 1 != s[i]) {
                        mex = s[i - 1] + 1;
                        break;
                    }
                }
                if (mex < cur) {
                    cout << -1 << endl;
                    exit(0);
                }
                ans.pb(v);
                col[v] = cur;
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        c[x].pb(i);
    }

    for(int i = 1; i <= n; i++) {
        for(auto v : c[i]) {
            dfs(v, i);
        }
    }

    for(auto i : ans) {
        cout << i << ' ';
    }
    cout << endl;
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
