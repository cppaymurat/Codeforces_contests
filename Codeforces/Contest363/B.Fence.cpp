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
int dp[maxN];
void solve() {
	int n, k;
	cin >> n >> k;
	vi a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < k; i++) {
		dp[0] += a[i];
	}
	for(int id = 1; id + k <= n; id++) {
		dp[id] = dp[id - 1] - a[id - 1] + a[id + k - 1];
	}
	int mn = (int)1e9;
	int ans;
	for(int i = 0; i + k <= n; i++) {
		if (dp[i] < mn) {
			mn = dp[i];
			ans = i + 1;
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