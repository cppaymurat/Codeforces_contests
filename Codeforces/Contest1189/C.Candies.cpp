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
	vector<int> s(n);
	vector<int> pref(n + 1, 0);
	vector<int> d(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		pref[i + 1] = pref[i] + s[i];
	}
	int q;
	cin >> q;
	while(q--) {
		int l, r;
		cin >> l >> r;
		cout << (pref[r] - pref[l - 1]) / 10 << endl;
	}
	return 0;
}