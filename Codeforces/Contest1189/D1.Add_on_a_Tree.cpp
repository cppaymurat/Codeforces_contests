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
	map<int,int> cnt;
	for(int i = 1; i < n; i++) {
		int l, r;
		cin >> l >> r;
		cnt[l]++;
		cnt[r]++;
	}
	for(int i = 1; i <= n; i++) {
		if (cnt[i] == 2) {
			return cout << "NO\n", 0;
		}
	}
	cout << "YES\n";
	return 0;
}