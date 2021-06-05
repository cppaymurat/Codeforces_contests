#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define vi vector<int>
#define F first
#define S second
#define pii pair<int,int>
#define vpii vector<pii>
#define vll vector<ll>
#define all(v) v.begin(), v.end()
const int maxN = (int)1e5 + 123;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9;
 
int dx[] = {-1, 1, 0, 0, -1, 1, 1, -1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
	
void MaxMercury() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll gcd(ll a, ll b) {
	if (b == 0) {
		return 1;
	}
	if (a == b) return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
ll lcm(ll a, ll b, ll c) {
	return lcm(lcm(a, b), c);
}
void solve() {
	/*
	int n;
	cout << gcd(9, 72) << endl;
	cout << lcm(9, 72);
	cin >> n;
	ll ans = 1;
	int a, b, c;
	for(ll i = n; i >= max(n - 150, 1); i--) {
		for(ll j = n; j >= max(n - 150, 1); j--) {
			for(ll k = n; k >= max(n - 150, 1); k--) {
				if (ans < lcm(i, j, k)) {
					a = i, b = j, c = k;
					ans = lcm(i, j, k);	
				}
			}
		}
	}
	cout << a << " " << b << " " << c << endl;
	cout << ans << endl;*/
}
vector<int> g1[maxN];
vector<int> g2[maxN];
vector<char> used;
vector<int> order;
vector<int> cost;
void dfs1(int V) {
	if (used[V]) return;
	used[V] = true;
	for(auto i : g1[V]) {
		dfs1(i);
	}
	order.pb(V);
}
void dfs2(int V, vi &ans) {
	if (used[V]) return;
	used[V] = true;
	for(auto i : g2[V]) {
		dfs2(i, ans);
	}
	ans.pb(cost[V - 1]);
}
void comp() {
	int n;
	cin >> n;
	used.assign(n+5, 0);
	cost.assign(n+5, 0);
	for(int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	int m;
	cin >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g1[u].pb(v);
		g2[v].pb(u);
	}
	for(int i = 1; i <= n; i++) {
		if (!used[i]) {
			dfs1(i);
		}
	}
	for(int i = 1; i <= n; i++) {
		used[i] = false;
	}
	reverse(all(order));
	vi ans;
	ll k = 0;
	vi coef;
	for(auto i : order) {
		if (!used[i]) {
			vi o;
			dfs2(i, o);
			ans.pb(*min_element(all(o)));
			int c = 0;
			for(auto i : o) {
				if (ans.back() == i) c++;
			}
			coef.pb(c);
		}
	}
	ll res = 0;
	for(auto i : ans) res += i;
	ll ans2 = 1;
	for(auto i : coef) {
		ans2 *= i;
		if (ans2 >= MOD) {
			ans2 -= MOD;
		}
	}
	cout << res << " " << ans2 % MOD;
}
int main() {
//	freopen("in.txt" ,"r", stdin);
	MaxMercury();
	int t = 1;
//	cin >> t;
	while(t--) {
		//solve();
		comp();
	}
	return 0;
}

