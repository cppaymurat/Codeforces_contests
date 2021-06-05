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

const int maxN = (int)1e3 + 123;
const int MOD = (int)1e9 + 7;

void solve() {
	int n, m;
	cin >> n >> m;
	vi a(n);
	map<int, int> cnt;
	vi pref(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}	
	for(int i = n - 1; i >= 0; i--) {
		cnt[a[i]]++;
		pref[i] = cnt.size();
	}
	for(int i = 1; i <= m; i++) {
		int l;
		cin >> l;
		cout << pref[l - 1] << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}