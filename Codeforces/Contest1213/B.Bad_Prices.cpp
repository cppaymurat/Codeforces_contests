#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	int mn = a[n - 1];
	for(int i = n - 2; i >= 0; i--) {
		if (a[i] > mn) {
			ans++;
		}
		mn = min(mn, a[i]);
	}
	cout << ans << endl;
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