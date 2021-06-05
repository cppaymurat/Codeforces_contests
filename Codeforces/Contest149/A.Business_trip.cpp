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
	int k;
	cin >> k;
	vi a(12);
	for(int i = 1; i <= 12; i++) {
		cin >> a[i - 1];
	}
	sort(a.begin(), a.end());
	if (k <= 0) {
	    cout << 0 << endl;
	    return;
	}
	for(int i = 11; i >= 0; i--) {
		k -= a[i];
		if (k <= 0) {
			cout << 12 - i << endl;
			return;
		}
	}
	cout << -1;
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