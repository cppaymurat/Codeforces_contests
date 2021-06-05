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
const int MOD = 1e9 + 7; // 998244353;
const ld  PI = acos(-1);
const ld  EPS = 3E-16;
const int ALPHA = 26;
const int N = (int)1e2 + 5;

int dp[N][N][N][2], a[N], even, odd, n;

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i])
            a[i] %= 2;
        else
            a[i] = -1;
    }

    even = n / 2;
    odd = n - even;

    for(int i = 0; i < n; i++) {
        if (a[i] != -1) {
            if (a[i])
                odd--;
            else
                even--;
        }
    }

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= even; j++)
            for(int k = 0; k <= odd; k++)
                for(int p = 0; p < 2; p++)
                    dp[i][j][k][p] = N;

    dp[0][even][odd][0] = dp[0][even][odd][1] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= even; j++) {
            for(int k = 0; k <= odd; k++) {
                for(int p = 0; p < 2; p++) {
                    if (dp[i][j][k][p] == N)
                        skip;
                    for(int q = 0; q < 2; q++) {
                        if (a[i] != -1 && a[i] != q)
                            skip;
                        int nj = j, nk = k;
                        if (a[i] == -1) {
                            if (q == 0)
                                nj--;
                            else
                                nk--;
                        }
                        if (nj < 0 || nk < 0)
                            skip;
                        int w = dp[i][j][k][p];
                        if (p != q)
                            w++;
                        dp[i + 1][nj][nk][q] = min(dp[i + 1][nj][nk][q], w);
                    }
                }
            }
        }
    }

    cout << min(dp[n][0][0][1], dp[n][0][0][0]) << endl;
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
