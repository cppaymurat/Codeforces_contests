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
 
const int maxN = (int)1e3 + 123;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9;
 
int dx[] = {-1, 1, 0, 0, -1, 1, 1, -1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
	
void MaxMercury() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
bool cmp(pii &a, pii &b) {
	return a.S < b.S;
}
void solve() {
	ll n, r, avg;
	cin >> n >> r >> avg;
	ll ans = 0;
	vpii ab(n);
	ll s = 0;
	for(int i = 0; i < n; i++) {
		cin >> ab[i].F >> ab[i].S;
		s += ab[i].F;
	}
	sort(ab.begin(), ab.end(), cmp);
	ll need;
	for(auto i : ab) {
		if (avg * n > s) {
			need = avg * n - s;
			if (i.F < r) {
				ans += min(need, r - i.F) * i.S;
				s += min(need, r - i.F);
			}
		} else break;
	}
	cout << ans << endl;
}
int main() {
// 	freopen("in.txt" ,"r", stdin);
	MaxMercury();
	int t = 1;
//	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}

