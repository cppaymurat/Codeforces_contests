#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define vpii vector<pii>

const int maxN = (int)1e5 + 123;
const int MOD = (int)1e9 + 7;
void solve() {
	int n;
	cin >> n;
	vi a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int ans = 1;
	map<int,int> hd;
	vi div;
	div.pb(a[0]);
	hd[a[0]] = 1;
	int c = 1;
	while(c < n) {
		int k = 0;
		for(int i = 0; i < n; i++) {
			if (!hd.count(a[i])) {
				bool flag = false;
				for(int j = 0; j < div.size(); j++) {
					if (a[i] % div[j] == 0) {
						hd[a[i]] = 1;
						flag = true;
						c++;
						break;
					}
				}
				if (!flag) {
					div.pb(a[i]);
					c++;
					hd[a[i]] = 1;
				}
			} else k++;
		}
	/*	for(int i = 0; i < div.size(); i++) {
			cout << div[i] << " ";
		}
		cout << endl;*/
		if (k == n) break;
	}
	cout << div.size() << endl;
}
int main() {
//	freopen("in.txt", "r", stdin);
	solve();
	return 0;
}