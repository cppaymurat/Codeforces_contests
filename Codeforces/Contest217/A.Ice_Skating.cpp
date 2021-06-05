#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define F first
#define S second
#define pii pair<int,int>
#define vpii vector<pii>
#define vll vector<ll>

const int maxN = (int)1e3 + 123;
const int MOD = (int)1e9 + 7;
vector<int> G[maxN];
vector<char> used(maxN);
int c = 0;
void dfs(int V) {
	if (used[V]) return;
	used[V] = true;
	c++;
	for(auto i : G[V]) {
		dfs(i);
	}
}
void solve() {
	int n;
	cin >> n;
	vi x(n), y(n);
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if (i != j) {
				if (x[i] == x[j] || y[i] == y[j]) {
					G[i].pb(j);
					G[j].pb(i);
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i);
			ans++;
		}
	}
	cout << ans - 1;
	
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}