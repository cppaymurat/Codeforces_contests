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

string func(string s) {
    int id1 = 0, id2 = 0;
    for(int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'b') {
            id1 = i + 1;
            break;
        }
    }
    for(int i = (int)s.size() - 1; i >= 0; i--) {
        if (s[i] == 'b') {
            id2 = i + 1;
            break;
        }
    }
    return to_string(id1) + " " + to_string(id2);
}

ll f(ll x) {
    return x * (1 + x) / 2;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    int need = -1;
    for(ll i = 1; i <= n; i++) {
        if (k <= f(i)) {
            need = i;
            break;
        }
    }

    string t = "";
    rep(i, 0, n)
        t += 'a';

    t[n - need - 1] = 'b';
    t[n - (k - f(need - 1))] = 'b';
    cout << t << endl;
}

void _() {
//    isFile = 1;
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
