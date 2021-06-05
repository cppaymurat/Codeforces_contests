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
 
const int maxN = (int)1e6 + 123;
const int MOD = (int)1e9 + 7;
string RGB[] = {"RGB", "GBR", "BRG"};
int mn, k;
string s;
void solve() {
	int n;
	cin >> n >> k;
	cin >> s;
	int j = 0;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	int id = 0;
	for(int i = 0; i < n; i++) {
		if (s[i] == RGB[0][j]) {
			cnt1++;
		}
		if (s[i] == RGB[1][j]) {
			cnt2++;
		}
		if (s[i] == RGB[2][j]) {
			cnt3++;
		}
		if (i >= k) {
			if (s[i - k] == RGB[0][(i - k) % 3] && cnt1) cnt1--;
			if (s[i - k] == RGB[1][(i - k) % 3] && cnt2) cnt2--;
			if (s[i - k] == RGB[2][(i - k) % 3] && cnt3) cnt3--;	
			mn = min(mn, min(k - cnt1, min(k - cnt2, k - cnt3)));
		} else
		if (i == k - 1) {
			mn = min(mn, min(k - cnt1, min(k - cnt2, k - cnt3)));
		}
		j++;
		j%=3;
		//cout << "i = " << i << ", cnt1 = " << cnt1 << ", cnt2 = " << cnt2 << " , cnt3 = " << cnt3 << endl;
	}
	cout << mn << endl;
}
int main() {
//	freopen("in.txt", "r", stdin);
	int t = 1;
	cin >> t;
	while(t--) {
		mn = maxN;
		solve();
	}
	return 0;
}