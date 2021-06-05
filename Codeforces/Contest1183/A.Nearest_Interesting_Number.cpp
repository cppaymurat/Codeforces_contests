#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>

#define F first
#define S second

const int maxN = (int)1e5 + 123;
const int MOD = (int)1e9 + 7;
int sum(int n) {
	int ans = 0;
	while(n > 0) {
		ans += n % 10;
		n /= 10;
	}
	return ans;
}
int main() {
	int a;
	cin >> a;
	for(int i = a; ; i++) {
		if (sum(i) % 4 == 0) {
			return cout << i << endl, 0;
		}
	}
  	return 0;
}