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
const double EPS = 1e-8;
const int ALPHA = 27;
const int N = (int)2e5 + 5;
const int M = 1234;

int a[N];
int cnt[N];

void solve() {
    int n;
    cin >> n;
    set<int> mex;
    vector<int> mb;
    bool bad = 0;
    map<int, int> huyak;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if (mex.count(a[i]))
            bad = 1;
        mex.ins(a[i]);
        if (*(--(mex.end())) == i && (int)mex.size() == i) {
            mb.pb(i);
            huyak[i] = 1;
        }
    }

    if (mb.empty() || !bad) {
        cout << 0 << endl;
        return;
    }

    mex.clear();
    vector<int> tb, ans;
    bad = 0;
    for(int i = n; i >= 1; i--) {
        if (mex.count(a[i])) {
            bad = 1;
        }
        mex.ins(a[i]);
        if (*(--(mex.end())) == (n - i + 1) && (int)mex.size() == (n - i + 1)) {
            if (huyak.count(i - 1)) {
                ans.pb(i - 1);
            }
        }
    }

    cout << ans.size() << endl;
    for(int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << ' ' << n - ans[i] << '\n';
    }
}

void _() {
    isFile = 0;
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
