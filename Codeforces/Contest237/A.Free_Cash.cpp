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

void solve() {
	int n;
	cin >> n;
	map<pii, int> d;
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		d[{x, y}]++;
	}
	int ans = 0;
	for(auto i : d) {
		ans = max(ans, i.second);
	}
	cout << ans;
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