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
string s;
map<pair<char, int>, int> m; 
map<char, int> d;
int sl;
int n;
void solve() {
	string t;
	cin >> t;
	int mx = -1;
	map<char, int> d2;
	for(int i = 0; i < t.length(); i++) {
		d2[t[i]]++;
		mx = max(mx, m[mp(t[i], d2[t[i]])]);
	}
	cout << mx << endl;
}
int main() {
	//freopen("in.txt", "r", stdin);
	cin >> sl;
	cin >> s;
	for(int i = 0; i < sl; i++) {
		d[s[i]]++;
		m[mp(s[i], d[s[i]])] = (i + 1);
	}
	int n;
	cin >> n;
	while(n--) {
		solve();
	}
	return 0;	
}