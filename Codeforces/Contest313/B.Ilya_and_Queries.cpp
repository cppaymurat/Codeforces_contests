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

const int maxN = (int)1e7 + 123;
const int MOD = (int)1e9 + 7;

void MaxMercury() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void solve() {
	string s;
	cin >> s;
	int m;
	cin >> m;
	int n = s.length();
	vi a(n + 1);
	for(int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1]) a[i + 1] = 1;
	}
	map<int, int> pref;
	for(int i = 1; i < n; i++) {
		pref[i + 1] += pref[i] + a[i];
	}
	while(m--) {
		int l, r;
		cin >> l >> r;
		cout << pref[r] - pref[l] << endl;
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