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
	ll n, a, b, c;
	cin >> n >> a >> b >> c;
	ll ans = 0;
	for(ll x = 0; x <= 4000; x++) {
		for(ll y = 0; y <= 4000; y++) {
			if (n - x * a - y * b >= 0 && (n - x * a - y * b) % c == 0) {
				ll z = (n - x * a - y * b) / c;
				if (ans < x + y + z) {
					ans = x + y + z;
					///cout << x << " " << y << " " << z << endl;
				}
			}
		}
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