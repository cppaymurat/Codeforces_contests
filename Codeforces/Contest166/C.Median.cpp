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

const int maxN = (int)1e6 + 123;
const int MOD = (int)1e9 + 7;

void MaxMercury() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void solve() {
	int n, x;
	cin >> n >> x;
	vi a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int id = 0;
	int ans = 0;
	map<int, vector<int> > pos;
	for(int i = 0; i < n; i++) {
		if (a[i] == x) {
			pos[x].pb(i + 1);
		}
	}
	if (pos[x].size() == 0) {
		vi q = a;
		q.pb(x);
		sort(q.begin(), q.end());
		int posx = 0;
		for(int i = 0; i < q.size(); i++) if (q[i] == x) posx = i + 1;
		int all = q.size();
		while(posx != (all + 1) / 2) {
			if (posx < (all + 1) / 2) {
				posx++;
				all++;
			} else {
				all++;
			}
		}
//		cout << posx << " " << all << " " << endl;
		cout << all - n << endl;
		return;
	} else {
		ans = (int)1e6;
		for(int i = 0; i < pos[x].size(); i++) {
			int posx = pos[x][i];
			int all = n;
			while(posx != (all + 1) / 2) {
				if (posx < (all + 1) / 2) {
					posx++;
				}
				all++;
			}
			ans = min(ans, all - n);
		}
		cout << ans << endl;
	}
}
int main() {
	MaxMercury();
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}