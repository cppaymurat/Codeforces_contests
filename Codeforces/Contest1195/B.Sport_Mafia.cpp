#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define vi vector<ll>
 
const int maxN = (int)1e5 + 123;
const int MOD = (int)1e9 + 7;

void solve() {
	ll n, k;
	cin >> n >> k;
	ll carry = 9 + 8 * 1ll * (n + k);
	cout << (ll)n - ((ll)(sqrt(carry) + 0.5) - 3) / 2 << endl;
}
int main() {
//	freopen("in.txt", "r", stdin);
	ll t = 1;
	while(t--) {
		solve();
	}
	
	return 0;
}