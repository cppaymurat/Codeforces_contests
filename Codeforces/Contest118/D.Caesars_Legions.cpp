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
const int maxN = (int)500 + 123;
const int MOD = (int)1e8;
const int INF = (int)1e9;
 
int dx[] = {-1, 1, 0, 0, -1, 1, 1, -1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
	
void MaxMercury() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll n1, n2, k1, k2;
ll dp[123][123][12][12];
void solve() {
	cin >> n1 >> n2 >> k1 >> k2;
	for(int f = 0; f <= n1; f++) {
		for(int h = 0; h <= n2; h++) {
			for(int kf = 0; kf <= k1; kf++) {
				for(int kh = 0; kh <= k2; kh++) {
					ll ans = 0;
					if (f + h == 0) ans = 1; else {
						if (f > 0 && kf > 0) {
							ans = (ans + dp[f - 1][h][kf - 1][k2]) % MOD;
						}
						if (h > 0 && kh > 0) {
							ans = (ans + dp[f][h - 1][k1][kh - 1]) % MOD;
						}
					}
					dp[f][h][kf][kh] = ans;
				}
			}
		}
	}
	cout << dp[n1][n2][k1][k2] << endl;
}
int main() {
//	freopen("in.txt" ,"r", stdin);
	MaxMercury();
	int t = 1;
//	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}