#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define vll vector<ll>
#define ull unsigned ll
#define pii pair<int, int>
#define point pii
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
 
#define isFile 0
#define NAME "taskA"
 
using namespace std;
 
const int maxN = (int)2e5 + 123;
const int MOD = (int)1e9 + 7;
const int INF = 1e9 + 12345;
const int CYCLE = -INF;
 
int dx[] = {1,  0, -1,  0,  1,  1, -1, -1};
int dy[] = {0,  1,  0, -1, -1,  1,  1, -1};
 
void MaxMercury() {
	if (isFile) {
		freopen(NAME".in", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);				
}
namespace MATH_CAL {
	const int mod = (int)1e9 + 7;
	inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
	inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
	inline int mul(int a, int b) { return (ll) a * b % mod; }
	inline void Add(int &a, int b) { (a += b) >= mod ? a -= mod : 0; }
	inline void Sub(int &a, int b) { (a -= b) < 0 ? a += mod : 0; }
	inline int qpow(int x, int n) { int r = 1; for ( ; n; n /= 2, x = mul(x, x)) if (n & 1) r = mul(r, x); return r; }
	inline int mod_inv(int x) { return qpow(x, mod - 2); }
} using namespace MATH_CAL;
int p[maxN];
int mx[maxN];
int sz[maxN];
void make_set(int a) {
	p[a] = a;
	mx[a] = a;
	sz[a] = 1;
}
int find_set(int a) {
	if (a != p[a]) return p[a] = find_set(p[a]);
	return a;
}
void unit_set(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (sz[a] < sz[b]) swap(a, b);
		p[b] = a;
		mx[a] = max(mx[a], mx[b]);
	}
}
void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		make_set(i);
	}	
	int ans = 0;
	for(int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		unit_set(u, v);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= mx[find_set(i)]; j++) {
			if (find_set(i) != find_set(j)) {
				ans++;
				unit_set(i, j);
			}
		}
		i = mx[find_set(i)];
	}
	cout << ans << endl;
}
int main() {
	MaxMercury();
	int t = 1;
	//cin >> t;
	while(t--) {
		solve();
	}	
	return 0;
}
