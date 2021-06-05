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

int cnt[N][ALPHA];

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int sz = n / k;

    for(int j = 0; j < k; j++) {
        for(int i = j; i < n; i += k) {
            cnt[j][s[i] - 'a']++;
        }
    }

    for(int j = 0; j < k / 2; j++) {
        for(int i = 0; i < ALPHA; i++) {
            cnt[j][i] += cnt[k - j - 1][i];
        }
    }

    ll ans = 0;
    for(int j = 0; j < (k % 2 ? 1 : 0) + k / 2; j++) {
        int mx = -1;
        for(int i = 0; i < ALPHA; i++) {
            mx = max(mx, cnt[j][i]);
        }
        if (j == k / 2 && k % 2) {
            ans -= sz;
        }
        ans += sz + sz - mx;
    }

    cout << ans << endl;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < ALPHA; j++) {
            cnt[i][j] = 0;
        }
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