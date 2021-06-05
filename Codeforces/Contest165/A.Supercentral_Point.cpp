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
	vpii xy;
	int ans = 0;
	map<int, vi> xx;
	map<int, vi> yy;
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		xy.pb({a, b});
		xx[a].pb(b);
		yy[b].pb(a);
	}
	for(int i = 0; i < n; i++) {
		int x = xy[i].F;
		int y = xy[i].S;
		bool up = false, down = false, left = false, right = false;
		for(auto j : xx[x]) {
			if (j > y) up =1;
			if (j < y) down = 1;
		}
		for(auto j : yy[y]) {
			if (j > x) left = 1;
			if (j < x) right = 1;
		}
		ans += up && down && left && right;
	}
	cout << ans << endl;
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