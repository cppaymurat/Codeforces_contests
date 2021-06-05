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
	ll n;
	cin >> n;
	int c4 = 0, c7 = 0;
	while(n % 7 && n > 0) {
		n -= 4;
		c4++;
	}
	if (n % 7 || n < 0) {
		cout << "-1" << endl;
		return 0;
	}
	if (n == 0) {
		for(int i = 1; i <= c4; i++) {
			cout << 4;
		}
		return 0;
	}
	c7 = n / 7;
	for(int i = 1; i <= c4; i++) {
		cout << 4;
	}
	for(int i = 1; i <= c7; i++) {
		cout << 7;
	}
	return 0;
}