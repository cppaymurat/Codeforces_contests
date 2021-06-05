#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define vi vector<int>
 
const int maxN = (int)1e5 + 123;
const int MOD = (int)1e9 + 7;
void solve() {
	/*for(int i = 1; i <= 100; i++) {
		cout << i << "-th in page " << i / 6 << endl;
	}*/
	ll n, m, k;
	cin >> n >> m >> k;
	ll ans = 1;
	deque<ll> st;
	for(int i = 0; i < m; i++) {
		ll t;
		cin >> t;
		st.push_back(t);
	}
	// 1 2 3 4 5 6 7 8 9 10 11 
	// 1 1 1 1 1 2 2 2 2 2 3 
	// 7 10 carry = 2
	// 
	ll carry = 0;
	ll page = (ll)(st.front() - 1) / k + 1;
	// 1; k
	// k + 1; 2 * k + 1;
	// 2 * k + 2; 2 * k + 2 + k
	
	while(!st.empty()) {
		if (page == (ll)(st.front() - 1) / k + 1) {
			st.pop_front();
			carry++;
		} else 
		break;
	}
	if (!st.empty()) ans++;
	ll carry2 = 0;
	page = (ll)(st.front() - 1 - carry) / k + 1;
	while(!st.empty()) {
		if (page == (ll)(st.front() - 1 - carry) / k + 1) {
			st.pop_front();
			carry2++;
		} else {
			carry += carry2;
			carry2 = 0;
			page = (ll)(st.front() - 1 - carry) / k + 1;
			ans++;
		}
	}
	cout << ans << endl;
}
int main() {
	int t = 1;
	//cin >> t;
	while(t--) {
		solve();
	}
	
	return 0;
}