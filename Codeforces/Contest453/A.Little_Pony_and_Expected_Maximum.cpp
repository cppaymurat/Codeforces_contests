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

const int maxN = (int)1e5 + 123;
const int MOD = (int)1e9 + 7;
int main() {
	double m, n;
	cin >> m >> n;
	double ans = 0;
	for(int i = 1; i <= m; i++) {
		double cf = pow(i * 1.0 / m, n) - pow((i - 1.0) / m, n);
		ans += i * cf;
	}
	printf("%.12lf", ans);
	return 0;
}