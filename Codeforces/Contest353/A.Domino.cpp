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

const int maxN = (int)2e3 + 123;
const int MOD = (int)1e9 + 7;
void solve() {
	int n;
	cin >> n;
	vi x(n + 1), y(n + 1);
	int sum_up = 0, sum_down = 0;
	int odd_x = 0;
	for(int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		sum_up += x[i];
		sum_down += y[i];
		odd_x += (x[i] % 2 != y[i] % 2);
	}
	if (odd_x % 2 || (sum_up % 2 == 1 && sum_down % 2 == 1 && odd_x == 0)) {
		cout << "-1\n";
		return;
	}
	if (!odd_x || (sum_up % 2 == 0 && sum_down % 2 == 0)) {
		cout << 0 << endl;
		return;
	}
	cout << 1;
	
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