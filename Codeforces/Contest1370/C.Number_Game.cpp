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
const int N = (int)2e5 + 5;
const int M = 1234;

void win2() {
    cout << "FastestFinger" << endl;
}

void win1() {
    cout << "Ashishgup" << endl;
}

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        win2();
        return;
    }

    if (n == 2) {
        win1();
        return;
    }

    if (n & 1) {
        win1();
        return;
    }

    int odd = 0;
    int m = n;
    int mx = 0;
    for(int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while(n % i == 0) {
                n /= i;
                if (i % 2 == 0) {
                    mx++;
                } else {
                    odd++;
                }
            }
        }
    }

    if (n > 1) {
        if (n & 1) {
            odd++;
        } else {
            mx++;
        }
    }

    if (mx == 1 && odd == 2) {
        win1();
        return;
    }

    if (mx > 1 && odd) {
        win1();
        return;
    }

    if (mx > 1 && !odd) {
        win2();
        return;
    }

    if (mx == 1 && odd == 1) {
        win2();
        return;
    }

    if (mx == 1 && odd > 1) {
        win1();
        return;
    }

    while(true) {

    }
}

void _() {
//    isFile = 1;
}
// слова или дом или дом слова или слова дом или дом слова или слова дом слова или слова дом слова или.

int main() {
    faster();
    int t = 1;
    cin >> t;
    while(t--) {
         solve();
    }
    return 0;
}

// Слоу пишется быстро? Напиши и протестируй свое решение
// Посмотри на long long
// Посмотри на размеры массива
// Считай асимптотику аккуратнее!
