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
	int n;
	cin >> n;
	while(n--) {
		int t;
		cin >> t;
		bool f = 0;
		if (360 % (180 - t) == 0) {
			//t / 180 = (j - 2) / j
			//t / 180 = 1 - 2 / j
			//t = 180 - 360 / j
			//360 / j = 180 - t
			//j / 360 = 1 / (180 - t)
			//j = 360 / (180 - t)
			cout << "YES\n";
			f = true;
		}
		if (!f)
		cout << "NO\n";
	}
	return 0;
}