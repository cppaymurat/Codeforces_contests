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
const int maxN = (int)(1e5) + 123;
const int MOD = (int)1e8;
const int INF = (int)1e9;
 
int dx[] = {-1, 1, 0, 0, -1, 1, 1, -1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
	
void MaxMercury() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

void solve() {
	int n;
	cin >> n;
	vi a(n);
	int ea = 0, eq = 0, oa = 0, oq = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		ea += a[i] % 2 == 0;
	}	
	oa = n - ea;
	int m;
	cin >> m;
	vi q(m);
	for(int i = 0; i < m; i++) {
		cin >> q[i];
		eq += q[i] % 2 == 0;
	}
	oq = m - eq;
	cout << (oa * 1ll * oq) + (ea * 1ll * eq) << endl;
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