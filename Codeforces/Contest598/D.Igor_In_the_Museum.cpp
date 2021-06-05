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
    string a[1234];
 //   map<pii, vpii> g;
    int comp[1111][1111];
    bool used_comp[1234567];
    int getFrom[1234567];
    int id = 1;
    int n, m;
    inline bool norm(pii a) {
    	return (a.F >= 1 && a.S >= 1 && a.F <= n && a.S <= m);
    }
    inline bool idu(pii V) {
    	return a[V.F][V.S] == '.';
    }
    bool used[1111][1111];
    ll ans = 0;
    inline void dfs(pii V) {
    	if (used[V.F][V.S]) return;
    	used[V.F][V.S] = 1;
   		comp[V.F][V.S] = id;    
    	for(int i = 0; i < 4; i++) {
    		if (norm(mp(dx[i] + V.F, dy[i] + V.S)) && !idu(mp(dx[i] + V.F, dy[i] + V.S))) {
    			getFrom[id]++;
    		}
    	}
    	for(int i = 0; i < 4; i++) {
    		if (norm(mp(dx[i] + V.F, dy[i] + V.S)) && idu(mp(dx[i] + V.F, dy[i] + V.S))) {
    			dfs(mp(dx[i] + V.F, dy[i] + V.S));
    		}
    	}
    	
    /*	for(auto to : g[V]) {
    		if (idu(to)) 
    			dfs(to);
    	}*/
    }
    void solve() {
    	int k;
    	cin >> n >> m >> k;
    	
    /*	for(int i = 1; i <= n; i++) {
    	
    		for(int j = 1; j <= m; j++) {
    		
    			for(int l = 0; l < 4; l++) {
    			
    				if (norm(mp(i + dx[l], j + dy[l]))) {
    					g[mp(i, j)].pb(mp(i + dx[l], j + dy[l]));
    				}
    				
    			}
    			
    		}
    		
    	}*/
    	
    	for(int i = 1; i <= n; i++) {
    	
    		cin >> a[i];
    		a[i] = "#" + a[i];
    		
    	}
    	
    	for(int i = 1; i <= n; i++) {
    	
    		for(int j = 1; j <= m; j++) {
    		
    			if (!used[i][j] && idu(mp(i, j))) {
    			
    				dfs(mp(i, j));
    				id++;
    				
    			}
    			
    		}
    		
    	}
    	
    	for(int i = 1; i <= k; i++) {
    	
    		int u, v;
    		cin >> u >> v;
    		int comp_id = comp[u][v];
    		ans = getFrom[comp_id];
    		cout << ans << endl;
    		ans = 0;
    		
    	}
    	
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