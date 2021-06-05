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
	vi a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int m;
	cin >> m;
	vi b(m);
	for(int i = 0; i < m; i++) {
		cin >> b[i];
	}
	sort(b.rbegin(), b.rend());
	int mx = 0;
	vi q;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if (a[j] > 0 && b[i] % a[j] == 0) {
				q.pb(b[i] / a[j]);
				mx = max(mx, b[i] / a[j]);
				a[j] = 0;
			}
		}
	}
	int ans = 0;
	for(auto i : q) {
		if (i == mx) ans++;
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