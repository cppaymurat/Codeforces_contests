#include <bits/stdc++.h>
#define isFile 0
#define NAME "taskA"
#define scan 1
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<short, short> pss;
typedef pair<double, double> pdd;

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
#define bpc(x) __builtin_popcount(x)
#define rev(a) reverse(all(a))
#define skip continue
#define read(a) for(auto &i : a) cin >> i
#define print(a) for(auto i : a) cout << i << ' '
#define unique(a) sort(all(a));    a.resize(unique(all(a)) - a.begin())

const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void faster() {
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
const int MAXN = (int)2e5 + 5;
const int MOD = 1e9 + 7; // 998244353
const ld  PI = acos(-1);
const ld  EPS = 3E-16;
const int ALPHA = 26;

int n, c;
int a[MAXN];
int b[MAXN];
int dp[MAXN][3];

void solve() {
    cin >> n >> c;
    for(int i = 1; i <= n - 1; i++) {
        cin >> a[i];
    }
    for(int j = 1; j <= n - 1; j++) {
        cin >> b[j];
    }
    dp[1][0] = 0;
    dp[1][1] = c;
    for(int i = 2; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][0] + a[i - 1], dp[i - 1][1] + b[i - 1]);
        dp[i][1] = min(dp[i - 1][0] + b[i - 1] + c, dp[i - 1][1] + b[i - 1]);
        dp[i][0] = min(dp[i][0], dp[i][1]);
    }

    for(int i = 1; i <= n; i++) {
        cout << dp[i][0] << ' ';
    }

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
