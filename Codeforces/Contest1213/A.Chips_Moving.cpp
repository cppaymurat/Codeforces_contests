#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int odd = 0;
	int even = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0) even++; else odd++;
	}
	cout << min(even, odd);
	
}
int main() {
	int t = 1;
	//cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}