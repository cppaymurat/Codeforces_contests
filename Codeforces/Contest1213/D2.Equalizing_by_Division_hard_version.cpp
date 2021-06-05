#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> layer[20];
void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<int> b(n);
	map<int, int> eq;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		eq[a[i]]++;
	}
	map<int,int> _eq = eq;
	for(int i = 0; i < n; i++) {
		if (eq[a[i]] >= k) {
			cout << 0 << endl;
			return;
		}
	}
	sort(a.rbegin(), a.rend());
	for(int i = 0; i < n; i++) {
		int h = a[i];
		int lay = 0;
		while(h >= 0) {
			layer[lay++].push_back(h);
			if (h != 0) 
			h /= 2; else break;
			layer[lay++].push_back(h);
			if (h != 0) 
			h /= 2; else break;
			if (h == 0) {
				layer[lay++].push_back(0);
				break;
			}
		}
	}
	int ans = 4000000;
	map<int, int> gx;
	map<int, int> px;
	for(int i = 0; i < 20; i++) {
		for(int j = 0; j < layer[i].size(); j++) {
			//cout << layer[i][j] << " ";
			gx[layer[i][j]]++;
			px[layer[i][j]] += i;
			if (gx[layer[i][j]] >= k) {
				ans = min(ans, px[layer[i][j]]);
			}
		}
	}
	cout << ans << endl;
}
int main() {
//	freopen("in.txt", "r", stdin);
	int t = 1;
//	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}