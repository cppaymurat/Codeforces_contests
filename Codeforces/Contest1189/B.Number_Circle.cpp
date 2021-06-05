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
	vector<int> a(n);
	deque<int> z;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int id1 = 0, id2 = n - 1;
	for(int i = 0; i < n; i++) {
		if (i % 2 == 0)
		z.push_back(a[id2--]);
		else
		z.push_front(a[id2--]);
	}
	for(int i = 0; i < n; i++) {
		if (i > 0 && i < n - 1) {
			if (z[i - 1] + z[i + 1] <= z[i]) return cout << "NO\n",0;
		}
		if (i == 0) {
			if (z[0] >= z[n - 1] + z[1]) return cout << "NO\n",0;
		}
		if (i == n - 1) {
			if (z[n - 1] >= z[n - 2] + z[0]) return cout << "NO\n", 0;
		}
	}
	cout << "YES\n";
	for(int i = 0 ; i < n; i++) {
		cout << z[i] << " ";
	}
	return 0;
}