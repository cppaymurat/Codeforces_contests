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
	int n, a, b;
	cin >> n >> a >> b;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if (i - 1 >= a && n - i <= b) ans++;
	}
	cout << ans << endl;
	return 0;
}