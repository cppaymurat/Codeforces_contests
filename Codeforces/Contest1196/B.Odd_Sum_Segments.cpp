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

void solve() {
	int n, k;
	cin >> n >> k;
	vi a(n);
	int odd = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		odd += a[i] % 2;
	}
	if (odd < k || odd % 2 != k % 2 || k > n) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	vi ans;
	for(int i = 0; i < n && k > 1; i++) {
		if (a[i] % 2 == 1) {
			cout << i + 1 << " ";
			k--;
		}
	}
	cout << n << endl;
}
int main() {
//	freopen("in.txt", "r", stdin);
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}