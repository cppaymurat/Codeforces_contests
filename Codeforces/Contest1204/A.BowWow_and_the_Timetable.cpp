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
	string s;
	cin >> s;
	ll ans = 0;
	ll power = 0;
	for(int i = 0; i < s.length(); i++) {
		if (s[i] == '1') {
			power = s.length() - i;
			break;
		}
	}
	ll right = 0;
	for(int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == '1') {
			right = s.length() - i;
			break;
		}
	}
	ans = power / 2;
	if (right != power && power % 2) ans++;
	cout << ans << endl;
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