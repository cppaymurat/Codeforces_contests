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
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void MaxMercury() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void solve() {
	int n;
	cin >> n;
	vpii a(n);
	pii ans;
	int mn = 1001;
	for(int i = 0; i < n; i++) {
		cin >> a[i].F;
		a[i].S = i + 1;
	}
	for(int i = 1; i < n; i++) {
		if (mn > abs(a[i].F - a[i - 1].F)) {
			mn = abs(a[i].F - a[i - 1].F);
			ans = mp(a[i].S, a[i - 1].S);
		}
	}
	if (mn > abs(a[0].F - a[n - 1].F)) {
		mn = abs(a[0].F - a[n - 1].F);
		ans = mp(a[0].S, a[n - 1].S);
	}
	cout << ans.F << " " << ans.S << endl;
	
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