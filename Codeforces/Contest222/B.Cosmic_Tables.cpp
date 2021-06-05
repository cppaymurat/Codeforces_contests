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

const int maxN = (int)1e3 + 123;
const int MOD = (int)1e9 + 7;
int a[maxN][maxN];
int row[maxN], column[maxN];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
		row[i] = i;
	}
	for(int i = 0; i < m; i++) {
		column[i] = i;
	}
		char c;
		int l, r;
	while(q--) {
		cin >> c >> l >> r;
		if (c == 'g') {
			printf("%d\n", a[row[l - 1]][column[r - 1]]);
		} else
		if (c == 'r') {
			swap(row[l - 1], row[r - 1]);
		} else
		{
			swap(column[r - 1], column[l - 1]);
		}
	}
	return 0;
}