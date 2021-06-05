#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
	ll n, m;
	cin >> n >> m;
	ll ans = 0;
	ll k = n / m;
	vector<int> digits;
	map<int,int> used;
	ll g = m % 10;
	for(int i = 0; i <= 100; i++) {
		if (used.count(g)) break;
		digits.push_back(g);
		used[g]++;
		g += m % 10;
		g %= 10;
	}
	for(int i = 0; i < digits.size(); i++) {
		ans += digits[i];
	//	cout << digits[i] << " ";
	}
	ll ost = k % digits.size();
	ans = ans * (k / digits.size());
	for(int i = 0; i < ost; i++) {
		ans += digits[i];
	//	cout << digits[i] << " ";
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