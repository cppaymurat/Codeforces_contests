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
	int n;
	cin >> n;
	vi a(n);
	map<int, vi> b;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		b[a[i]].pb(i + 1);
	}	
	vpii ans;
	for(int i = 1; i <= 100000; i++) {
		if (b.count(i)) {
			if (b[i].size() == 1) {
				ans.pb(mp(i, 0));
			} else  {
				int d = b[i][1] - b[i][0];
				bool normba = da;
				for(int j = 1; j < b[i].size(); j++) {
					if(b[i][j] - b[i][j - 1] != d) {
						normba = net;
						break;
					}
				}
				if (normba) {
					ans.pb(mp(i, d));
				}
			}
		}
	}
	cout << ans.size() << endl;
	for(auto i : ans) {
		cout << i.F << " " << i.S << endl;
	}
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

