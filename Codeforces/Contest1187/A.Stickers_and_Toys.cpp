#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define vll vector<ll>
#define vpii vector<pii>
#define mii map<int,int>
#define F first
#define S second

const int maxN = (int)1e5 + 123;
const int MOD = (int)1e9 + 7;
void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	int t1 = 0, t2 = 0, t3 = 0;
	t1 = b;
	t2 = c;
	t3 = t1 + t2 - a;
	t2 -= t3;
	t1 -= t3;
	cout << max(t1, t2) + 1 << endl;
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	while(n--) {
		solve();
	}
	return 0;	
}