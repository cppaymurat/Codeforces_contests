#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll,ll>

const int maxN = (int)1e5 + 123;
const int MOD = (int)1e9 + 7;
void solve() {
	int n;
	cin >> n;
	vector<pii> a(n - 1);
	int all = 0;
	int t;
	cin >> t;
	all += t;
	vi ans;
	int sum = t;
	for(int i = 1; i < n; i++) {
		cin >> a[i - 1].F;
		sum += a[i - 1].F;
		a[i - 1].S = i + 1;
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < n - 1; i++) {
		if (t / 2 >= a[i].F) {
			all += a[i].F;
			ans.pb(a[i].S);
		} else {
		//	cout << sum << " " << all << endl;
			if (sum / 2 >= all) {
				cout << 0;
				return;
			} else {
				cout << ans.size() + 1 << endl;
				cout << 1 << " ";
				for(int i = 0; i < ans.size(); i++) {
					cout << ans[i] << " ";
				}
				cout << endl;
				return;
			}
		}
	}
	if (sum / 2 >= all) {
		cout << 0;
		return;
	}
	cout << ans.size() + 1 << endl;
	cout << 1 << " ";
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