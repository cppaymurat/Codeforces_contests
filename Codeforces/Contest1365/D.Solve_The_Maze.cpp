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

int a[51][51];
int used[51][51];

int gett(char c) {
    if (c == '.')
        return 0;
    if (c == '#')
        return 1;
    if (c == 'G') {
        return 3;
    }
    if (c == 'B') {
        return 4;
    }
    return -1;
}

int n, m;
int g;

bool good(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != 1);
}

void dfs(int x, int y) {
    if (a[x][y] == 1)
        return;

    if (used[x][y])
        return;
    used[x][y] = 1;
    if (a[x][y] == 3) {
        g--;
    }

    for(int i = 0; i < 4; i++) {
        int to_x = dx[i] + x;
        int to_y = dy[i] + y;
        if (good(to_x, to_y) && a[to_x][to_y] != 4) {
            dfs(to_x, to_y);
        }
    }
}

void solve() {
    cin >> n >> m;
    g = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            used[i][j] = 0;
            char c;
            cin >> c;
            a[i][j] = gett(c);
            g += c == 'G';
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if (a[i][j] == 3) {
                for(int x = 0; x < 4; x++) {
                    int to_x = dx[x] + i;
                    int to_y = dy[x] + j;
                    if (good(to_x, to_y) && a[to_x][to_y] == 4) {
                        cout << "No\n";
                        return;
                    }
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if (a[i][j] == 4) {
                for(int x = 0; x < 4; x++) {
                    int to_x = dx[x] + i;
                    int to_y = dy[x] + j;
                    if (good(to_x, to_y) && a[to_x][to_y] == 0) {
                        a[to_x][to_y] = 1;
                    }
                }
            }
        }
    }

    if (g == 0) {
        cout << "Yes\n";
        return;
    }

    dfs(n, m);

    if (g != 0) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
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

// Слоу пишется быстро? Напиши и протестируй свое решение
// Посмотри на long long
// Посмотри на размеры массива
