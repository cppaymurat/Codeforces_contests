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
const int maxN = (int)(2e5) + 123;
const int MOD = (int)1e8;
const int INF = (int)1e9;
 
int dx[] = {-1, 1, 0, 0, -1, 1, 1, -1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
	
void MaxMercury() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int gcd(int a, int b) {
	while(b != 0) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}
int a[maxN];
int b[maxN];
int d[maxN];
void solve() {
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		d[l]++;
		d[r + 1]--;
	}
	for(int i = 1; i <= n; i++) {
		b[i] = b[i - 1] + d[i];
	}
//	for(int i = 1; i <= n; i++) {
//		cout << b[i] << " ";
//	}
//	cout << endl;
	sort(b + 1, b + 1 + n);
	ll ans = 0;
	for(int i = n; i >= 1; i--) {
		ans += b[i] * 1ll * a[i];
	}
	cout << ans << endl;
}
int main() {
//	freopen("in.txt" ,"r", stdin);
//	MaxMercury();
	int t = 1;
//	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}