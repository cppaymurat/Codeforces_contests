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

void solve() {
	int n;
	cin >> n;
	if (n % 4 == 1) {
		cout << 0 << " " << "A" << endl;
	} else
	if(n % 4 == 3) {
		cout << 2 << " " << "A" << endl;
	} else
	if (n % 4 == 0) {
		cout << 1 << " " << "A" << endl;
	} else
	cout << 1 << " " << "B" << endl;
}
int main() {
	int t = 1;
	//cin >> t;
	while(t--) {
		solve();
	}
	
	return 0;
}