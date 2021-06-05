#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>

const int maxN = (int)1e5 + 123;
const int MOD = (int)1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vi a(n);
	int neg = 0, pos = 0;
	int zero = 0;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] >= 1) {
			pos++;
			ans += a[i] - 1;
		} else
		if (a[i] <= -1) {
			neg++;
			ans += abs(a[i]) - 1;
		} else {
			zero++;
		}
	}
	if (neg % 2 == 0) {
		cout << ans + zero << endl;
		return;
	}
	if (neg % 2 == 1 && zero) {
		cout << ans + zero << endl;
		return;
	}
	cout << ans + 2 << endl;
	
}
int main() {
	//freopen("in.txt", "r", stdin);
	int t = 1;
	//cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}