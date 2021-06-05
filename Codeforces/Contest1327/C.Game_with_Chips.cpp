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
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const ld  PI = acos(-1);
const ld  EPS = 3E-16;
const int ALPHA = 27;
const int N = (int)2e2 + 5;
const int M = 123;

int n, m, k;
int sx[N], sy[N], fx[N], fy[N];

void solve() {
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++) {
        cin >> sx[i] >> sy[i];
    }

    for(int i = 1; i <= k; i++) {
        cin >> fx[i] >> fy[i];
    }

    string ans = "";

    for(int i = 1; i < n; i++) {
        ans += "U";
    }
    for(int i = 1; i < m; i++) {
        ans += "L";
    }

    for(int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            for(int j = 1; j < m; j++) {
                ans += "R";
            }
        } else {
            for(int j = m; j > 1; j--) {
                ans += "L";
            }
        }
        if (i != n)
            ans += "D";
    }

    if ((int)ans.size() > n * m * 2) {
        cout << -1 << endl;
        return;
    }

    cout << ans.size() << endl;
    cout << ans << endl;
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
