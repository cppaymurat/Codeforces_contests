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

unordered_map<ll, ll> cnt;
map<int, vector<int>> pos;
ll pref[N];

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(all(a));
    for(int i = 0; i < n; i++) {
        if (cnt[a[i]] >= k) {
            cout << 0 << endl;
            return;
        }
        pos[a[i]].pb(i);
    }
    vector<ll> b = a;
    unique(b);
    vector<ll> dp(b.size() + 1, INF);
    int sz = (int) b.size();
    // dp[i] - сколько операции требуется для числа b[i]
    ll sum = 0;
    pref[0] = a[0];
    for(int i = 0; i < n; i++) {
        sum += a[i];
        if (i > 0) {
            pref[i] = a[i] + pref[i - 1];
        }
    }

    pref[n] = pref[n - 1];

    dp[0] = sum - (n - k) - b[0] * n;
    dp[sz - 1] = (b.back() - 1) * (n - cnt[b.back()]) - pref[n - cnt[b.back()] - 1] + (k - cnt[b.back()]);
    ll ans = INF;
//    cout << dp[0] << ' ' << dp[sz - 1] << endl;

    for(int i = 1; i < sz - 1; i++) {
        ll can_get_up = pos[b[i]][0];
        ll can_get_down = n - pos[b[i]].back() - 1;
        ll to_up = (b[i] - 1) * (can_get_up) - pref[can_get_up - 1];
        ll to_down = (sum - pref[n - can_get_down - 1]) - (b[i] + 1) * (can_get_down);
//        cout << sum - pref[n - can_get_down - 1] << ' ' << can_get_down << endl;
        ll has = cnt[b[i]];
        ll need = k - has;
        ll h = INF, f = INF;
        if (can_get_down >= need) {
            h = to_down + need;
        }
        if (can_get_up >= need) {
            f = to_up + need;
        }
        ll cur = min(h, f);
        if (cur == INF) {
            cur = to_up + to_down + need;
        }
//        cout << cur << endl;
        ans = min(ans, cur);
    }

     ans = min(ans, dp[0]);
     ans = min(ans, dp[sz - 1]);

    cout << max(0ll, ans) << endl;
}

void _() {
   // isFile = 1;
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
