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
	string s;
	cin >> s;
	vector<pair<int, char> > q;
	for(int i = 0; i < s.length(); i++) {
		int p = 0;
		char c = s[i];
		while(i < s.length() && s[i] == c) {
			p++;
			i++;
		}
		i--;
		q.pb(mp(p, c));
	}
	for(int i = 0; i < q.size(); i++) {
		if (q[i].F > 2) {
			q[i].F = 2;
			i--;
		}
	}
	for(int i = 0; i < q.size() - 1; i++) {
		if (q[i].F == q[i + 1].F && q[i].F == 2) {
			q[i + 1].F = 1;
		}
	}
	for(auto i : q) {
		for(int j = 0; j < i.F; j++) {
			cout << i.S;
		}
	}
}
int main() {
// 	freopen("in.txt" ,"r", stdin);
	MaxMercury();
	int t = 1;
//	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}

