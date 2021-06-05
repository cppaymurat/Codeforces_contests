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
int f[maxN][4];
int x[maxN], y[maxN];
int xl = -1e5, xr = 1e5, yl = -1e5, yr = 1e5;
void func(int x, int y, int id) {
	if (id == 1) xl = max(xl, x);
	if (id == 2) yr = min(yr, y);
	if (id == 3) xr = min(xr, x);
	if (id == 4) yl = max(yl, y);
}
void solve() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		for(int j = 0; j < 4; j++) {
			cin >> f[i][j];
			if (!f[i][j]) {
				func(x[i], y[i], j + 1);
			}
		}
	}
	if (xr < xl || yr < yl) {
		cout << 0 << endl;
	} else {
		cout << 1 << " ";
		cout << xl << " " << yl << endl;
	}
	
}
int main() {
//	freopen("in.txt", "r", stdin);
	int t = 1;
	cin >> t;
	while(t--) {
		xl = -1e5, xr = 1e5, yl = -1e5, yr = 1e5;
		solve();
	}
	return 0;
}