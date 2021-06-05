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
const int maxN = (int)(2e5) + 123;
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
	vi p(n + 1);
	vi path(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> p[i];
		path[p[i]] = i;
	}
	for(int i = 1; i <= n; i++) {
		ll q = 1;
		int f = i;
		while(path[f] != i) {
			f = path[f];
			q++;
		}
		cout << q << " ";
	}
	cout << endl;
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