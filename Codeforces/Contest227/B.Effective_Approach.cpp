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
	int n;
	cin >> n;
	vi a(n);
	map<int, int> posl;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if (posl.count(a[i]) == false) posl[a[i]] = i + 1;
	}
	map<int, int> posr;
	for(int i = n - 1; i >= 0; i--) {
		if (posr.count(a[i]) == false) posr[a[i]] = i + 1; 
	}
	int m;
	cin >> m;
	ll l = 0, r = 0;
	while(m--) {
		int x;
		cin >> x;
		l += posl[x];
		r += n - posr[x] + 1;
	}
	cout << l << " " << r << endl;
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