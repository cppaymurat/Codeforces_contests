#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define vll vector<ll>
#define ull unsigned ll
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>

#define isFile 0
#define NAME "taskA"
const int maxN = (int)1e5 + 123;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e16;

void MaxMercury() {
	if (isFile) {
		freopen(NAME".in", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);				
}
int d; 
bool makePalindrome(string s) {
	map<char, int> cnt;
	int odd = 0;
	for(auto i : s) {
		cnt[i]++;
	}
	for(auto i : cnt) {
		odd += i.second % 2;
	}
	d = odd;
	return odd <= 1;
}
void solve() {
	int n;
	int ans = 0;
	cin >> n;
	vi len;
	int c1 = 0, c0 = 0, c2 = 0;
	vi cc0, cc1;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		d = 0;
		if (makePalindrome(s)) {
			if (d == 0) c0++; else c1++;
		} else
		c2++;
	}
	ans += c0 + c1 + c2 - c2 % 2;
	c2 %= 2;
	ans += min(c2, c1);
	cout << ans << endl;
}
int main() {
	MaxMercury();								
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}