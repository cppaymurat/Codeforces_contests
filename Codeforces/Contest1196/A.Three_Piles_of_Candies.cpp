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
#define pll pair<ll,ll>

const int maxN = (int)1e6 + 123;
const int MOD = (int)1e9 + 7;

void solve() {
	ll a, b, c;
	cin >> a >> b >> c;
	cout << (ll)(a + b + c) / 2ll << endl;
}
int main() {
//	freopen("in.txt", "r", stdin);
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}