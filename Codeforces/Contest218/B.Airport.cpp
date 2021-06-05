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
	int n, m;
	cin >> n >> m;
	vi a(m);
	map<int, int> tickets;
	for(int i = 0; i < m; i++) {
		cin >> a[i];
		for(int j = 1; j <= a[i]; j++) tickets[j]++;
	}
	int ans1 = 0;
	int ans2 = 0;
	int n1 = n;
	map<int, int> sec = tickets;
	vpii ticket;
	for(auto i : tickets) {
		ticket.pb(i);
	}
	sort(ticket.rbegin(), ticket.rend());
	int n2 = n;
	for(auto i : ticket) {
		int need = n2;
		if (need > 0) {
			int canGive = min(i.S, need);
			need -= canGive;
			ans2 += canGive * i.F;
			n2 -= canGive;
		}
	}
	sort(a.begin(), a.end());
	int need = n;
	for(auto i : a) {
		while(i > 0 && need > 0) {
			need--;
			ans1 += i;
			i--;
		}
	}
	cout << ans2 << " " << ans1 << endl;
	
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

