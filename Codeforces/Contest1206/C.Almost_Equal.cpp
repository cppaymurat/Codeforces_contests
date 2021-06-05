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
vi ans;
int n;
bool check() {
	int s = 0;
	for(int i = 0; i < n; i++) {
		s += ans[i];
	}
	int d = s;
	for(int i = 1; i + n - 1 < ans.size(); i++) {
		d -= ans[i - 1];
		d += ans[n + i - 1];
		if (abs(s - d) > 1) {
			return false;
		}
	}
	return true;
}
void solve() {
	cin >> n;
	int id = 0;
	vi ids;
	for(int i = 1; i <= n; i++) {
		ids.pb(id);
		id = id + n;
		id %= 2 * n;
		ids.pb(id);
		id--;
		id = max(id, 0);
		id %= 2 * n;
	}
	ans.resize(2 * n);
	int sep = 1;
	for(int i = 0; i < ids.size(); i++) {
		ans[ids[i]] = sep;
		sep++;
	}
	if (!check()) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
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