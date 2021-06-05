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
const int maxN = (int)1e5 + 123;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9;
 
int dx[] = {-1, 1, 0, 0, -1, 1, 1, -1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
	
void MaxMercury() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll gcd(ll a, ll b) {
	if (b == 0) {
		return 1;
	}
	if (a % b == 0) return b;
	if (b % a == 0) return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
ll lcm(ll a, ll b, ll c) {
	return lcm(lcm(a, b), c);
}
void solve() {
	int n;
	cin >> n;
	ll ans = 1;
	for(ll i = n; i >= max(n - 150, 1); i--) {
		for(ll j = n; j >= max(n - 150, 1); j--) {
			for(ll k = n; k >= max(n - 150, 1); k--) {
				ll p = lcm(i, j, k);
				if (ans < p) {
					ans = p;
				}
			}
		}
	}
	cout << ans << endl;
}
int main() {
//	freopen("in.txt" ,"r", stdin);
	MaxMercury();
	int t = 1;
//	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}

