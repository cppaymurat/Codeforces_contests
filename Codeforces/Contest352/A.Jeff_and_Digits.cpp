#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pii pair<int,int>

#define F first
#define S second

const int maxN = (int)1e5 + 123;
const int MOD = (int)1e9 + 7;

int main() {
	int n;
	cin >> n;
	int c0 = 0, c5 = 0;
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (t == 0) c0++; else c5++;
	}
	if ((c5 * 5) % 9 == 0 && c0 > 0) {
		if (c5 > 0) {
		for(int i = 0; i < c5; i++) {
			cout << 5;
		}
		for(int i = 0; i < c0; i++) {
			cout << 0;
		} } else cout << 0;
		cout << endl;
	} else 
	if (c0 == 0) {
		cout << -1;
	} else 
	if (c5 == 0) {
		cout << 0;
	} else {
		int sum = 5 * c5;
		while(sum % 9 != 0) {
			sum -= 5;
		}
		if (sum > 0) {
			for(int i = 0; i < sum / 5; i++) {
				cout << 5;
			}
			for(int i = 0; i < c0; i++) {
				cout << 0;
			}
		} else cout << 0;
	}
	return 0;
}