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
    int dx[] = {1,  1, -1,  -1,  2,  2, -2, -2};
    int dy[] = {2, -2,  2,  -2,  1, -1,  1, -1};
     
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
    
    void solve() {
		int n, m;
		cin >> n >> m;
		vi a(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(all(a));
	//	reverse(all(a));
		int ans = 0;
		for(int i = n - 1; m > 0 && i >= 0; i--) {
			m -= a[i];
			ans++;
		}
		cout << ans << endl;
    }
    int main() {
    	MaxMercury();
    	int t = 1;
    //	cin >> t;
    	while(t--) {
    		solve();
    	}	
    	return 0;
    }