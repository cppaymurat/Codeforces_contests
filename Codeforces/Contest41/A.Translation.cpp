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
	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	if (a != b) cout << "NO\n"; else cout << "YES\n";
	return 0;
}