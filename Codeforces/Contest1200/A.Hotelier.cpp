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
#define vpii vector<pii>
#define pll pair<ll,ll>
 
const int maxN = (int)1e6 + 123;
const int MOD = (int)1e9 + 7;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vi ans(10, 0);
	int posLeft = 0, posRight = 9;
	for(int i = 0; i < s.length(); i++) {
		if (s[i] == 'L') {
			while(ans[posLeft] == 1) posLeft++;
			ans[posLeft] = 1;
			posLeft++;
		} else
		if (s[i] == 'R') {
			while(ans[posRight] == 1) posRight--;
			ans[posRight] = 1;
			posRight--;
		} else {
			ans[s[i] - '0'] = 0;
			if (s[i] - '0' < posLeft) {
				posLeft = s[i] - '0';
			} else
			if (s[i] - '0' > posRight) {
				posRight = s[i] - '0';
			}
		}
	}
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}
}
int main() {
//	freopen("in.txt", "r", stdin);
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}