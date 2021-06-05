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

const ll  INF = 9e18;
const int inf = 2e9;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const ld  PI = acos(-1);
const ld  EPS = 3E-16;
const int ALPHA = 27;
const int N = (int)1e5 + 5;
const int M = 1234;

ll get(string s) {
    int m = (int) s.size();
    ll res = 0;
    rev(s);
    for(int i = 0; i < m; i++) {
        res += (s[i] - '0') * (1ll << i);
    }
    return res;
}

string get(ll x) {
    if (x == 0)
        return "0";

    string ans = "";
    while(x) {
        ans += (char)(x % 2 + '0');
        x >>= 1;
    }
    rev(ans);
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    map<ll, bool> bad;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        bad[get(s)] = 1;
    }

    ll l = 0, r = (1ll << m);
    ll need = (r - n - 1) >> 1;
    ll ans = r >> 1;
    while(r - l >= 0) {
        ll mid = (l + r) >> 1;
        ll q = mid;
        for(auto x : bad) {
            q -= (x.fr <= mid);
        }

        if (q >= need) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }

    string res = get(ans);
    while(res.size() < m)
        res = "0" + res;
    cout << res << endl;
}

void _() {
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
