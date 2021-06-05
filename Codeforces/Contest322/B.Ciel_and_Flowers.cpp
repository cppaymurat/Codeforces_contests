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
	int a, b, c;
	cin >> a >> b >> c;
	int ans2 = min(a, min(b, min(c, 2)));
	int _a = a, _b = b, _c = c;
	a -= ans2, b-= ans2, c -= ans2;
	ans2 += a / 3 + b / 3 + c / 3;
	a = _a, b = _b, c = _c;
	int ans1 = a / 3 + b / 3 + c / 3;
	a %= 3;
	b %= 3;
	c %= 3;
	ans1 += min(a, min(b, c));
	cout << max(ans1, ans2);
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