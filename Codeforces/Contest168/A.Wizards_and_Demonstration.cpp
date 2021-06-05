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
#include <iostream>
#include <clocale>

using namespace std;

int main() {
	ll n, x, y;
	cin >> n >> x >> y;
	if (n * 1ll * y / 100.0 <= x) {
		cout << 0 << endl;
		return 0;
	}
	// n * y / 100 <= x
	// (n + z) * y / 100 <= (x + z)
	ll left = 0;
	ll right = (int)1e9;
	ll mid;
	while(left < right) {
		mid = left + (right - left) / 2;
		if (n / 100.0 * 1ll * y <= (ll)(x + mid)) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}
	cout << right << endl;
	return 0;
}