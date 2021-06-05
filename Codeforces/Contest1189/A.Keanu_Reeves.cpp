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

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (n % 2 == 1) {
		cout << 1 << endl;
		cout << s << endl;
		return 0;
	}
	int c = 0, k = 0;
	int ans = 0;
	for(int i = 0; i < s.length(); i++) {
		if (s[i] == '1') c++; else k++;
	}
	if (c == k) {
		cout << 2 << endl;
	} else cout << 1 << endl;
	bool flag = true;
	if (c == k) flag = false;
	for(int i = 0; i < s.length(); i++) {
		if (s[i] == '1') c--; else k--;
		cout << s[i];
		if (c != k && !flag) {
		 	cout << " ";
		 	flag = true;
		}
	}
	return 0;
}