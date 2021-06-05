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
const int MAXN = (int)2e3 + 5;
const int MOD = 1e9 + 7; // 998244353
const ld  PI = acos(-1);
const ld  EPS = 3E-16;
const int ALPHA = 26;

int cnt[63];
int knt[63];
ull q[63];
void solve() {
    q[0] = 1;
    for(int i = 1; i < 63; i++) {
        q[i] = q[i - 1] * 2;
    }
    ull x, y;
    cin >> x >> y;

    if (x == y) {
        if (x == 0) {
            cout << 0 << endl;
            return;
        }
        cout << 1 << endl << x << endl;
        return;
    }

    if (x > y) {
        cout << -1 << endl;
        return;
    }

    ull X = x;
    for(int i = 62; i >= 0; i--) {
        if (X >= q[i]) {
            cnt[i]++;
            X -= q[i];
        }
    }

    vector<ull> ans;
    ans.pb(x);
    y -= x;

    for(int i = 62; i >= 0; i--) {
        if (y >= q[i] + q[i]) {
            y -= q[i] + q[i];
            knt[i] += 2;
        }
    }

    if (y > 0) {
        cout << -1 << endl;
        return;
    }

    for(int i = 62; i >= 0; i--) {
        if (knt[i] && (ans[0] & q[i]) == 0) {
            ans[0] |= q[i];
            knt[i]--;
        }
    }

    bool flag = 1;
    while(flag) {
        ull cur = 0;
        flag = 0;
        for(int i = 62; i >= 0; i--) {
            if (knt[i]) {
                cur |= q[i];
                knt[i]--;
                if (knt[i]) {
                    flag = 1;
                }
            }
        }
        ans.pb(cur);
    }

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
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
