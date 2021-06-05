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

void solve() {
	int n, l, r;
	cin >> n >> l >> r;
	ll mn = n - l + 1;
	ll mx = 1;
	ll mx2 = 0;
	for(int i = 1; i < l; i++) {
		mn += 1 << i;
	}
	for(int i = 1; i < r; i++) {
		mx += 1 << i;
	}
	int carry = (1 << (r - 1));
	mx2 += mx;
	for(int i = r; i < n; i++) {
		mx2 += carry;
	}
	cout << mn << " " << mx2 << endl;
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