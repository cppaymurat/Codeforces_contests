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
	int s, n;
	cin >> s >> n;
	vector<pii> xy(n);
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		xy[i] = mp(x, y);
	}
	sort(xy.begin(), xy.end());
	for(int i = 0; i < n; i++) {
		if (xy[i].F < s) {
			s += xy[i].S;
		} else {
			return cout << "NO\n", 0;
		}
	}
	cout << "YES\n";
	return 0;
}