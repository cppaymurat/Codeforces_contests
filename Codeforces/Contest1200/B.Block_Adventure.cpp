#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define mp make_pair

#define F first
#define S second

#define pii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define pll pair<ll,ll>
 
const int maxN = (int)1e6 + 123;
const int MOD = (int)1e9 + 7;

void solve() {
	ll n, m, k;
	cin >> n >> m >> k;
	vi h;
	for(int i = 0; i < n; i++) {
		ll t;
		cin >> t;
		h.pb(t);
	}
	for(int i = 0; i < n - 1; i++) {
		if (h[i] > h[i + 1]) {
			m += h[i] - max(h[i + 1] - k, 0ll);
		} else
		{
			if (h[i + 1] - h[i] <= k) {
				m += h[i] - max(h[i + 1] - k, 0ll);
			} else {
				if (abs(h[i + 1] - h[i] - k) <= m) {
					m -= abs(h[i + 1] - h[i] - k);
				} else {
					cout << "NO\n";
					return;
				}
			}
		}
	}
	cout << "YES\n";
}
int main() {
	//freopen("in.txt", "r", stdin);
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}