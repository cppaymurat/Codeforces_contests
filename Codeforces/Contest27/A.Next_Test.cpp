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
	int n;
	cin >> n;
	map<int,int> a;
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		a[t]++;
	}
	for(int i = 1; i <= 3001; i++) {
		if (!a[i]) {
			cout << i << endl;
			return;
		}
	}
}
int main() {
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}