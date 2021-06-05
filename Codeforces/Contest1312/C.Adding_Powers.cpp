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
const int MAXN = (int)1e6 + 5;
const int MOD = 1e9 + 7; // 998244353
const ld  PI = acos(-1);
const ld  EPS = 3E-16;
const int ALPHA = 26;

ull q[111];
int cnt[111];
int id;

void solve() {
    ull n, k;
    cin >> n >> k;
    id = 1;

    for(int i = 0; i < 64; i++)
        cnt[i] = 0,
        q[i] = 0;

    q[0] = 1;
    for(int i = 1; i < 64; i++) {
        q[i] = q[i - 1] * k;
        if (q[i] < q[i - 1])
            break;
        id++;
    }

    vull a(n);
    bool bad = 0;
    int c = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];

        if (!a[i])
            skip;

        for(int x = id - 1; x >= 0; x--) {
            if (a[i] >= q[x]) {
                a[i] -= q[x];
                if (!cnt[x])
                    c++;
                cnt[x]++;
                if (cnt[x] > 1)
                    bad = 1;
            }
        }

        if (a[i] != 0) {
            bad = 1;
        }
    }

//    for(int i = 0; i < id; i++)
//        cout << cnt[i] << ' ';
//    cout << '\n';


    if (!bad)
        cout << "YES\n";
    else
        cout << "NO\n";
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
