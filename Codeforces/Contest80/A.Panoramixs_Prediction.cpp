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
	int n, m;
	cin >> n >> m;
	int k = n + 1;
	bool prime = false;
	while(prime == false) {
		bool flag = true;
		if (k <= 1) flag = false;
		for(int i = 2; i * i <= k; i++) {
			if (k % i == 0) {
				k++;
				flag = false;
				break;
			}
		}
		if (flag) break;
	}
	if (k != m) {
		cout << "NO\n";
	} else cout << "YES";
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