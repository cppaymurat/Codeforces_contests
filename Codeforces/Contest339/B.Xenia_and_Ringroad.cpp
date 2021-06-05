#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e5 + 5;
const int MOD = (int)1e9 + 7;
#define ll long long
#define mp make_pair
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>

#define F first
#define S second

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	ll ans = 0;
	int pos = 1;
	for(int i = 0; i < m; i++) {
		int t;
		cin >> t;
		if (t >= pos) {
			ans += t - pos;
		} else {
			ans += (n - pos);
			ans += t;
		}
		pos = t;
	}
	cout << ans << endl;
	return 0;
}