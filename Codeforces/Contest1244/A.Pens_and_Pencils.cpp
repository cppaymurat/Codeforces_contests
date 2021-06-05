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
 
const int maxN = (int)1e3 + 123;
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
	int a, b, c, d, k;
	cin >> a >> b >> c >> d >> k;	
	int kr = a / c + (a % c ? 1 : 0);
	int rc = b / d + (b % d ? 1 : 0);
	if (kr + rc > k) {
		cout << -1 << endl;
	} else cout << kr << " " << rc << endl;
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

