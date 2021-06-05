#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pii pair<int,int>

#define F first
#define S second

const int maxN = (int)1e5 + 123;
const int MOD = (int)1e9 + 7;

int main() {
	int n, m;
	cin >> n >> m;
	vi a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int ans = 0;
	for(int i = 0; i < m; i++) {
		if (a[i] < 0)
		ans += a[i]; else break;
	}
	ans *= -1;
	cout << ans;
	return 0;
}