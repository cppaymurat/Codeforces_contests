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
	int n, k;
	cin >> n >> k;
	int d = k + 1;
	for(int i = d; i >= 1; i--) {
		cout << i << " ";
	}
	for(int i = k + 2; i <= n; i++) {
		cout << i << " ";
	}
	return 0;
}