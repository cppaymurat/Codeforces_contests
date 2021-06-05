#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int ans = 0;
	int mx = -1;
	while(n--) {
		int a, b;
		cin >> a >> b;
		ans -= a;
		ans += b;
		mx = max(mx, ans);
	}
	cout << mx << endl;
	return 0;
}