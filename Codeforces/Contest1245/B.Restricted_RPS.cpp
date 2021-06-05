#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define x first
#define F first
#define S second
#define y second
#define vll vector<ll>
#define ull unsigned ll
#define pii pair<int, int>
#define point pii
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define all(v) v.begin(), v.end()
#define sz(v) v.size()

#define isFile 0
#define NAME "taskA"

using namespace std;

const int maxN = (int)1e5 + 123;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e8;

int dx[] = {1,  1, -1,  -1,  2,  2, -2, -2};
int dy[] = {2, -2,  2,  -2,  1, -1,  1, -1};

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
	int n;
	cin >> n;
	int a, b, c;
	cin >> a >> b >> c;
	string s;
	int win = 0;
	cin >> s;
	map<char, char> g;
	g['R'] = 'P';
	g['P'] = 'S';
	g['S'] = 'R';
	string ans = "";
	for(auto i : s) {
		if (i == 'R' && b > 0) {
			ans += g[i];
			win++;
			b--;
		} else
		if (i == 'S' && a > 0) {
			ans += g[i];
			win++;
			a--;
		} else
		if (i == 'P' && c > 0) {
			ans += g[i];
			c--;
			win++;
		} else
		ans += "#";
	}
	if (win >= (n + 1) / 2) {
		cout << "YES\n";
		for(int i = 0; i < ans.length(); i++) {
			if (ans[i] == '#') {
				if (a > 0) {ans[i] = 'R'; a--;} else
				if (b > 0) {ans[i] = 'P';b--;} else
				if (c > 0) {ans[i] = 'S';c--;}
			}
		}
		cout << ans << endl;
	} else {
		cout << "NO\n";
	}
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