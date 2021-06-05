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
 
int dx[] = {-1, 1, 0, 0, -1, 1, 1, -1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
	
void MaxMercury() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
vi p;
int x, a, y, b;
ll cont(ll len) {
	ll A = 0, B = 0, AB = 0;
	for(int i = 1; i <= len; i++) {
		if (i % a == 0 && i % b == 0) AB++; else
		if (i % a == 0) A++; else
		if (i % b == 0) B++;
	}
	ll id = 0;
	ll ans = 0;
	for(int i = 0; i < AB; i++) {
		ans += p[id] / 100 * (x + y);
		id++;
	}
	for(int i = 0; i < A; i++) {
		ans += p[id] / 100 * x;
		id++;
	}
	for(int i = 0; i < B; i++) {
		ans += p[id] / 100 * y;
		id++;
	}
	return ans;
}
void solve() {
	int n;
	cin >> n;
	p.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> p[i];
	}
	sort(p.rbegin(), p.rend());
	cin >> x >> a >> y >> b;
	if (x < y) {
		swap(x, y);
		swap(a, b);
	}
	ll k;
	cin >> k;
	ll l = 0, r = n + 1, m = -1;
	while(r - l > 1) {
		m = (l + r) / 2;
		ll res = cont(m);
		if (res >= k) {
			r = m;
		} else
		{
			l = m;
		}
	}
	if (r > n) cout << -1 << endl; else
	cout << r << endl;
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