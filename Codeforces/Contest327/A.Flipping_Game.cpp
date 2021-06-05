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

const int maxN = (int)1e6 + 123;
const int MOD = (int)1e9 + 7;

void MaxMercury() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int dp[123][123];
void solve() {
	int n;
	cin >> n;
	vi a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int l, r;
	int ans = -1;
	for(int i = 0; i < n; i++) {
		l = i;
		for(int j = i; j < n; j++) {
			r = j;
			for(int k = l; k <= r; k++) {
				dp[l][r] += 1 - a[k];
			}
			for(int i = 0; i < l; i++) dp[l][r] += a[i];
			for(int i = r + 1; i < n; i++) dp[l][r] += a[i];
			ans = max(ans, dp[l][r]);
		}
	}
	cout << ans;
}
int main() {
	MaxMercury();
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}