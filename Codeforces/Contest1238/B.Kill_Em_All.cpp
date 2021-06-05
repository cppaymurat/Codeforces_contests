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
#define net false
#define da true
#define idontthinkso continue;
 
const int maxN = (int)1e6 + 123;
const int MOD = (int)1e9 + 7;
 
int dx[] = {-1, 1, 0, 0, -1, 1, 1, -1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
	
void MaxMercury() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void solve() {
	int n, r;
	cin >> n >> r;
	map<int, int> m;
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		m[t]++;
	}
	int add = r;
	vpii q;
	for(auto i : m) {
		q.pb(i);
	}
	int ans = 1;
	for(int i = q.size() - 2; i >= 0; i--) {
		if (q[i].first - add > 0) {
			add += r;
			ans++;
		} else break;
	}
	cout << ans << endl;
}
int main() {
//	freopen("in.txt" ,"r", stdin);
	MaxMercury();
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
 