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

ll q[93];

void solve() {
    int n;
    cin >> n;
    vll a(n);
    vll pref_max(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) {
            pref_max[i] = a[i];
        } else {
            pref_max[i] = max(pref_max[i - 1], a[i]);
        }
    }

    vll suff_min(n);
    for(int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            suff_min[i] = a[i];
        } else {
            suff_min[i] = min(suff_min[i + 1], a[i]);
        }
    }

    ll diff = -INF;
    for(int i = 0; i < n - 1; i++) {
//        cout << pref_max[i] << ' ' << suff_min[i + 1] << '\n';
        if (pref_max[i] > suff_min[i + 1]) {
            diff = max(diff, pref_max[i] - suff_min[i + 1]);
        }
    }

    if (diff == -INF) {
        cout << 0 << endl;
        return;
    }

    ll s = 0;
    for(int i = 0; i <= 64; i++) {
        s += q[i];
        if (s >= diff) {
            cout << i + 1 << endl;
            return;
        }
    }


}

void _() {
    isFile = 0;
}

int main() {
    faster();
    int t = 1;
    q[0] = 1;
    for(int i = 1; i <= 64; i++) {
        q[i] = q[i - 1] * 2;
    }
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
