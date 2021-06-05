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
const int N = (int)2e5 + 5;
const int M = 1234;

ll get(vector<ll> &pref, ll l, ll r) {
    return pref[r] - (l == 0 ? 0 : pref[l - 1]);
}

void solve() {
    int n;
    cin >> n;
    vector<bool> alive(n, 1);
    vector<bool> kills_next(n, 0);
    vector<ll> KPI(n, 0);
    vector<pair<ll, ll>> monster(n);
    vector<ll> pref(n, 0);
    vector<int> ends_at(n, -1);
    vector<ll> dmg(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> monster[i].fr >> monster[i].sc;
        if (i == 0) {
            pref[i] = monster[i].fr;
        } else {
            pref[i] += pref[i - 1] + monster[i].fr;
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        monster[i].sc = min(monster[i].sc, monster[(i + 1) % n].fr);
    }
    ll min_dmg = monster[0].sc;
    for(int i = 0; i < n; i++) {
        ans += monster[i].fr - monster[i].sc;
        min_dmg = min(min_dmg, monster[i].sc);
    }
    ans += min_dmg;
    cout << ans << endl;
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
