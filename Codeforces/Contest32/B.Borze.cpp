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
	for(int i = 0; i < s.length(); i++) {
		if (s[i] == '-') {
			if (s[i + 1] == '-') {
				cout << 2;
			} else {
				cout << 1;
			}
			i++;
		} else {
			cout << 0;
		}
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