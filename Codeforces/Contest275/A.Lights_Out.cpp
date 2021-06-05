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
int m[4][4];
char nat(char x) {
	return (x == '1' ? '0' : '1');
}
void solve() {
	string s[5] = {".....", ".111.", ".111.", ".111.", "....."};
	for(int i = 1; i <= 3; i++) {
		for(int j = 1; j <= 3; j++) {
			cin >> m[i][j];
			m[i][j] %= 2;
			if (m[i][j]) {
				s[i][j] = nat(s[i][j]);
				s[i - 1][j] = nat(s[i - 1][j]);
				s[i + 1][j] = nat(s[i + 1][j]);
				s[i][j + 1] = nat(s[i][j + 1]);
				s[i][j - 1] = nat(s[i][j - 1]);
				
				/*for(int i = 1; i <= 3; i++) {
					for(int j = 1; j <= 3; j++) {
						cout << s[i][j];
					}
					cout << endl;
				}*/
			}
		}
	}
	for(int i = 1; i <= 3; i++) {
		for(int j = 1; j <= 3; j++) {
			cout << s[i][j];
		}
		cout << endl;
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