#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>

#define F first
#define S second

const int maxN = (int)1e5 + 123;
const int MOD = (int)1e9 + 7;
void solve() {
	int n, k;
	cin >> n >> k;
	vi a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if (a[n - 1] - a[0] > 2 * k) {
		cout << -1 << endl;
		return;
	}
	cout << a[0] + k << endl;
}
int main() {
	//freopen("in.txt", "r",stdin);
	int n;
	cin >> n;
	while(n--) {
		solve();
	}
  	return 0;
}