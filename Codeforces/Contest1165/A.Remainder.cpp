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

vi G[maxN];
void solve() {
	int n;
	cin >> n;
	int x, y;
	cin >> x >> y;
	string s;
	cin >> s;
	string d = s.substr(n - x, x + 1);
	int ans = 0;
	string a = "";
	for(int i = 0; i < x; i++) {
		a += '0';
	}
	a[a.length() - y - 1] = '1';
	for(int i = 0; i < d.length(); i++) {
		if (d[i] != a[i]) ans++;
	}
	cout << ans << endl;
}
int main() {
	int t = 1;
	while(t--) {
		solve();
	}
	return 0;
}