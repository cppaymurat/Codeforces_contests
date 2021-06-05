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
void solve() {
	int t, sx, sy, ex, ey;
	cin >> t >> sx >> sy >> ex >> ey;
	bool doplyvu = net;
	string s;
	cin >> s;
	for(int i = 0; i < s.length(); i++) {
		if (s[i] == 'E') {
			if (sx >= ex) idontthinkso;
			sx++;
		}
		if (s[i]  == 'W') {
			if (sx <= ex) idontthinkso;
			sx--;
		}
		if (s[i]  == 'S') {
			if (sy <= ey) idontthinkso;
			sy--;
		}
		if (s[i]  == 'N') {
			if (sy >= ey) idontthinkso;
			sy++;
		}
		if (sx == ex && sy == ey) {
			cout << i + 1 << endl;
			doplyvu = da;
			return;
		}
	}
	cout << -1;
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

