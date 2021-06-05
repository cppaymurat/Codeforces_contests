#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define vll vector<ll>
#define ull unsigned ll
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>

#define isFile 0
#define NAME "taskA"

using namespace std;

const int maxN = (int)1e5 + 123;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e16;

int dx[] = {0,  0,  1, -1,  1, -1, -1,  1};
int dy[] = {1, -1,  0,  0,  1, -1,  1, -1};

void MaxMercury() {
	if (isFile) {
		freopen(NAME".in", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);				
}
void solve() {
	ll a, b, n;
	cin >> a >> b >> n;
	cout << -(-a * ((n + 1) / 2) + (b * (n / 2))) << endl;
}
int main() {
	MaxMercury();
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}	
	return 0;
}