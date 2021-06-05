#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define F first
#define S second
#define pii pair<int,int>
const int maxN = (int)1e5 + 6;
const int MOD = (int)1e9 + 7;
void solve() {
	int n, m;
	cin >> n >> m;
	string ans = "";
	if (n > m) {
		ans += "B";
		n--;
	} else {
		ans += "G";
		m--;
	}
	int id = 0;
	while(n || m) {
		if (ans[id] == 'B' && m) {
			ans += 'G';
			m--;
		} else 
		if (ans[id] == 'G' && n) {
			ans += 'B';
			n--;
		} else
		{
			if (n) {
				ans += 'B';
				n--;
			} else {
				ans += 'G';
				m--;
			}
		}
		id++;
	}
	cout << ans << endl;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}