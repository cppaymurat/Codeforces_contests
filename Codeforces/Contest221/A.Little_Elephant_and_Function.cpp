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
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void MaxMercury() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void f(vi &a, int n) {
	if (n == 1) return;
	swap(a[n - 1], a[n - 2]);	
	f(a, n - 1);
}
void solve() {
	int n;
	cin >> n;
	vi a(n);
	iota(a.begin(), a.end(), 1);
	f(a, n);
	for(int i = 0; i < n; i++) cout << a[i] << " ";
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