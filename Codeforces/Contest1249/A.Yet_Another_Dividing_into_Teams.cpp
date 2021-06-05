#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define vi vector<int>
#define F first
#define S second
#define pii pair<int,int>
#define vpii vector<pii>
#define vll vector<ll>
#define all(v) v.begin(), v.end()
const int maxN = (int)(1e5) + 123;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9;

int dx[] = {-1, 1, 0, 0, -1, 1, 1, -1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

void MaxMercury() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void solve() {
	int n;
	cin >> n;
	vi a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}	
	sort(a.begin(), a.end());
	int ans = 0;
	for(int i = 0; i < n - 1; i++) {
		if (a[i] + 1 == a[i + 1]) {
			cout << 2 << endl;
			return;
		}
	}
	cout << 1 << endl;
}
int main() {
//	freopen("in.txt" ,"r", stdin);
	MaxMercury();
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}