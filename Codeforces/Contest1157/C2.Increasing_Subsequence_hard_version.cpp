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

int a[MAXN], n, l, r;
vector<int> ans1, ans2;
vector<int> ans;
string res1 = "";
string res2 = "";
string res = "";

void checkLeft() {
    res1 = res;
    ans1 = ans;
    int L = l, R = r;
//    cout << "CheckLeft: " << endl;
    while(L <= R) {
        if (a[L] > ans1.back()) {
//            cout << a[L] << ' ';
            ans1.pb(a[L]);
            res1 += "L";
            L++;
        } else
            break;
    }
//    cout << '\n';
}

void checkRight() {
    res2 = res;
    ans2 = ans;
    int L = l, R = r;
//    cout << "CheckRight: " << endl;
    while(L <= R) {
        if (a[R] > ans2.back()) {
            ans2.pb(a[R]);
//            cout << a[R] << ' ';
            res2 += "R";
            R--;
        } else
            break;
    }
//    cout << '\n';
}

void compare() {
    if (res1.size() > res2.size())
        res = res1;
    else
        res = res2;
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    l = 0, r = n - 1;
    ans.pb(-1);
    while(l <= r) {
        if (a[l] > ans.back() && a[r] > ans.back()) {
            if (a[l] > a[r]) {
                ans.pb(a[r]);
                res += "R";
                r--;
            } else
            if (a[l] < a[r]) {
                ans.pb(a[l]);
                res += "L";
                l++;
            } else {
                checkLeft();
                checkRight();
                compare();
                break;
            }
        } else
        if (a[l] > ans.back()) {
            ans.pb(a[l]);
            res += "L";
            l++;
        } else
        if (a[r] > ans.back()) {
            ans.pb(a[r]);
            res += "R";
            r--;
        }
        else
            break;
    }

    cout << res.size() << endl;
    cout << res << endl;
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
