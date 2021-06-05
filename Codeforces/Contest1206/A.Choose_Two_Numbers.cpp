#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>

const int maxN = (int)1e5 + 123;
const int MOD = (int)1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vi a(n);
	map<int,int> ex;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		ex[a[i]]++;
	}
	int m;
	cin >> m;
	vi b(m);
	for(int i = 0; i < m; i++) {
		cin >> b[i];
		ex[b[i]]++;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int c = a[i] + b[j];
			if (!ex.count(c)) {
				cout << a[i] << " " << b[j] << endl;
				return;
			}
		}
	}
}
int main() {
	//freopen("in.txt", "r", stdin);
	int t = 1;
	//cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}