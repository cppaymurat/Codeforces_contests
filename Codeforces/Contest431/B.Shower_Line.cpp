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
#define net false
#define da true
#define idontthinkso continue;
 
const int maxN = (int)1e6 + 123;
const int MOD = (int)1e9 + 7;
 
int dx[] = {-1, 1, 0, 0, -1, 1, 1, -1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
	
void MaxMercury() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int g[10][10];
ll check(vi p) {
	ll res = 0;
	for(int i = 1; i <= 4; i++) 
	for(int j = i; j <= 4; j+=2) {
		res += g[p[j - 1]][p[j]];
		res += g[p[j]][p[j - 1]];
	}
	return res;
}
void solve() {
	for(int i = 1; i <= 5; i++) {
		for(int j = 1; j <= 5; j++) {
			cin >> g[i][j];
		}
	}
	vi p(5);
	for(int i = 1; i <= 5; i++) p[i - 1] = i;
	
	ll ans = check(p);
	while(next_permutation(p.begin(), p.end())) {
		ans = max(ans, check(p));
	}
	cout << ans << endl;
}
int main() {
//	freopen("in.txt" ,"r", stdin);
	MaxMercury();
	int t = 1;
//	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}

