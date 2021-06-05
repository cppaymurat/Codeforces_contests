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

int cnt[MAXN];
set<int> s;

void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for(int i = 0; i < n; ++i) {
        cin >> b[i];
        cnt[b[i]]++;
        s.ins(b[i]);
    }

    for(int i = 0; i < n; i++) {
        int x = a[i];
        auto y = s.lower_bound(n - x);
        if (y != s.end()) {
            a[i] = (x + *y) % n;
            cnt[*y]--;
            if (cnt[*y] == 0) {
                s.erase(y);
            }
        } else {
            a[i] = (x + *(s.begin())) % n;
            cnt[*(s.begin())]--;
            if (cnt[*begin(s)] == 0) {
                s.erase(begin(s));
            }
        }
        cout << a[i] << ' ';
    }
    cout << '\n';
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
