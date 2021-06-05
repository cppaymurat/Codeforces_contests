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

const int maxN = (int)1e7 + 123;
const int MOD = (int)1e9 + 7;
bool prime[maxN];
void getPrimes() {
	for(int i = 2; i < maxN; i++) {
		prime[i] = true;
	}
	prime[0] = prime[1] = false;
	for(int i = 2; i < maxN; i++) {
		if (prime[i]) {
			for(int j = i + i; j < maxN; j += i) {
				prime[j] = false;
			}
		}
	}
}
void solve() {
	getPrimes();
	int n;
	cin >> n;
	int c = 0;
	for(int i = 1; i < maxN; i++) {
		if (prime[i] && c < n) {
			c++;
			cout << i << " ";
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}