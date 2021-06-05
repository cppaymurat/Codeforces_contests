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

const int maxN = (int)2e3 + 123;
const int MOD = (int)1e9 + 7;
ll dp[maxN][maxN];
void solve() {
	ll n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		dp[1][i] = 1;
	}
	for(int i = 1; i <= k; i++) 
	for(int j = 1; j <= n; j++) {
		for(int q = 1; q * q <= j; q++) {
			if (j % q == 0) {
				dp[i][j] += dp[i - 1][q];
				if (j / q != q) {
					dp[i][j] += dp[i - 1][j / q];
				}
				if (dp[i][j] >= MOD) {
					dp[i][j] -= MOD;
				}
			}
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		//cout << dp[k][i] << endl;
		ans += dp[k][i];
		if (ans >= MOD) {
			ans -= MOD;
		}
	}
	cout << ans % MOD;
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