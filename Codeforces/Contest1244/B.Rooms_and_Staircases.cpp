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
const int INF = (int)1e9;
 
int dx[] = {-1, 1, 0, 0, -1, 1, 1, -1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
	
void MaxMercury() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int n;
string s;
void solve() {
	cin >> n;
	cin >> s;
	s = "#" + s;
	int ans = 0;
	vi pos;
	for(int i = 1; i <= n; i++) {
		if (s[i] == '1') {
		 	pos.pb(i);
		}
	}
	if (pos.size() == 0) {
		cout << n << endl;
		return;
	} 
	if (pos.size() == 1) {
		cout << max(pos[0], n - pos[0] + 1) * 2 << endl;
		return;
	}
	sort(pos.begin(), pos.end());
	int l = pos[0];
	int r = pos[pos.size() - 1];
	if (l == 1 || r == n) {
		cout << 2 * n << endl;
		return;
	}
	//00100010
	ans = max(r * 2, (n - l + 1) * 2);
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

