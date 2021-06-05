#include <bits/stdc++.h>
using namespace std;
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
const int maxN = (int)1e5 + 123;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e16;

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
	string s;
	cin >> s;
	vector<pair<char, int>> d;
	if (s.length() == 1) {
		d.pb(mp(s[0], 1));
	}
	int k = 1;
	for(int i = 1; i < (int)s.length(); i++) {
		if (s[i] == s[i - 1]) {
			k++;
		} else {
			d.pb(mp(s[i - 1], k));
			k = 1;
		}
	}
	if (!d.empty() && d.back().F != s[s.length() - 1]) d.pb(mp(s[s.length() - 1], k)); else
	if (d.empty()) d.pb(mp(s[0], s.length()));
	map<char, int> m;
	for(auto i : d) {
		if (i.S % 2) {
			m[i.F]++;
		}
	}
	for(char i = 'a'; i <= 'z'; i++) {
		if (m[i]) cout << i;
	}
	cout << endl;
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