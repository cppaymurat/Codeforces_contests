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
const int MAXN = (int)1e3 + 5;
const int MOD = 1e9 + 7; // 998244353
const ld  PI = acos(-1);
const ld  EPS = 3E-16;
const int ALPHA = 26;

int n;
char matrix[MAXN][MAXN];
bool used[MAXN][MAXN];
pair<int, int> from[MAXN][MAXN];
string paste = "ULDR";
string reved = "DRUL";

bool isGood(char x) {
    return x == 'C' || x == 'U' || x == 'D' || x == 'R' || x == 'L';
}

void panic() {
    cout << "INVALID\n";
    exit(0);
}

int prx = -1, pry = -1;

void dfs(int x, int y) {
    if (used[x][y])
        return;
    used[x][y] = 1;
    for(int k = 0; k < 4; k++) {
        int xx = x + dx[k], yy = y + dy[k];
        if (matrix[xx][yy] == '?') {
            if (prx == -1 && pry == -1) {
                prx = x, pry = y;
            }
            if (from[xx][yy] == mp(prx, pry)) {
                matrix[xx][yy] = paste[k];
                dfs(xx, yy);
            }
        }
    }
}

void solve() {
    cin >> n;

    for(int i = 0; i <= n + 1; i++)
        for(int j = 0; j <= n + 1; j++)
            matrix[i][j] = '#';

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int x, y;
            cin >> x >> y;
            if (x == i && y == j) {
                matrix[i][j] = 'X';
            } else
            if (x == -1 && y == -1) {
                matrix[i][j] = 'C';
            } else {
                matrix[i][j] = '?';
                from[i][j] = {x, y};
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if (isGood(matrix[i][j])) {
                int last = -1;
                for(int k = 0; k < 4; k++) {
                    if (matrix[i + dx[k]][j + dy[k]] == 'C') {
                        matrix[i + dx[k]][j + dy[k]] = paste[k];
                        last = k;
                    }
                }

                if (last != -1 && matrix[i][j] == 'C')
                    matrix[i][j] = reved[last];
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if (matrix[i][j] == 'X') {
                prx = i, pry = j;
                dfs(i, j);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if (matrix[i][j] == '?' || matrix[i][j] == 'C') {
                panic();
            }
        }
    }

    cout << "VALID\n";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << matrix[i][j];
        }
        cout << '\n';
    }
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
