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

void MaxMercury() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void solve() {
	string s;
	cin >> s;
	vi num;
	for(int i = 0; i < s.length(); i+=2) {
		num.pb(s[i] - '0');
	}
	sort(num.begin(), num.end());
	for(int i = 0; i < num.size(); i++) {
		if (i != num.size() - 1)cout << num[i] << "+"; else cout << num[i];
	}
}
int main() {
	MaxMercury();
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}