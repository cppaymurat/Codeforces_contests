#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define vi vector<int>
 
const int maxN = (int)3e5 + 123;
const int MOD = (int)1e9 + 7;
int s[3];
int old[3];
char c[3];
bool isK() {
	if (s[0] == s[1] && s[1] == s[2] && c[1] == c[0] && c[0] == c[2]) return true;
	return false;
}
bool isS() {
	if (c[1] == c[0] && c[0] == c[2]) {
		if (s[2] - s[1] == 1 && s[1] - s[0] == 1) return true;
	}
	return false;
}
void solve() {
	for(int i = 0; i < 3; i++) {
		cin >> s[i] >> c[i];
		old[i] = s[i];
	}
	sort(s, s + 3);
	if (isK() || isS()) {
		cout << 0 << endl;
		return;
	}
	if (c[0] != c[1] && c[0] != c[2] && c[1] != c[2]) {
		cout << 2 << endl;
		return;
	}
	if (c[0] == c[1] && c[1] == c[2]) {
		if (s[1] - s[0] <= 2 || s[2] - s[1] <= 2) {
			cout << 1 << endl;
			return;
		}
		cout << 2 << endl;
		return;
	}
	if (s[1] - s[0] > 2 && s[2] - s[1] > 2) {
		cout << 2 << endl;
		return;
	}
	if (c[0] == c[1]) {
		if (abs(old[0] - old[1]) <= 2) {
			cout << 1 << endl;
			return;
		}
	} else
	if (c[1] == c[2]) {
		if (abs(old[2] - old[1]) <= 2) {
			cout << 1 << endl;
			return;
		}
	}
	if (c[0] == c[2]) {
		if (abs(old[2] - old[0]) <= 2) {
			cout << 1 << endl;
			return;
		}
	}
	cout << 2 << endl;
}
int main() {
	int t = 1;
	//cin >> t;
	while(t--) {
		solve();
	}
	
	return 0;
}