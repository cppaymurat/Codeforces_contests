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
void check(int start, int id) {
	int j = 0;
	int cnt = 0;
	for(int i = start; i < start + k; i++) {
		if (s[i] == RGB[id][j]) {
			cnt++;
		}
		j++;
		j%=3;
	}
	mn = min(mn, k - cnt);
}
void solve() {
	int n;
	cin >> n >> k;
	cin >> s;
	for(int i = 0; i < s.length() - k + 1; i++) {
		check(i, 0);
		check(i, 1);
		check(i, 2);
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