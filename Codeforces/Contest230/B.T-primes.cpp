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

void MaxMercury() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void solve() {
	ll n;
	cin >> n;
	for(ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		ll q = sqrt(x);
		if (q * 1ll * q == x) {
			bool flag = false;
			if (x <= 1) flag = true;
			for(ll j = 2; j * 1ll * j <= q; j++) {
				if (q % j == 0) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				cout << "YES\n";
			} else cout << "NO\n";
		} else cout << "NO\n";
	}
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