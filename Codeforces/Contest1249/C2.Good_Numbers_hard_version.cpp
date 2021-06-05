#include <bits/stdc++.h>
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

using namespace std;

const int maxN = (int)1e5 + 123;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e16;

int dx[] = {0,  0,  1, -1,  1, -1, -1,  1};
int dy[] = {1, -1,  0,  0,  1, -1,  1, -1};

void MaxMercury() {
	if (isFile) {
		freopen(NAME".in", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);				
}
ll q[50];
ll gen(ll mask) {
	ll ans = 0;
	for(int i = 0; i < 40; i++) {
		if ((mask >> i) & 1) {
			ans += q[i];
		}
	}
	return ans;
}
void solve() {
	ll left = 1, right = q[39];
	ll m;
	ll n;
	cin >> n;
	while(left < right) {
		m = (left + right) >> 1;
		if (gen(m) >= n) {
			right = m;
		} else {
			left = m + 1;
		}
	}
	cout << gen(left) << endl;
}
int main() {
	q[0] = 1;
	for(int i = 1; i <= 39; i++) {
		q[i] = q[i - 1] * 3;
	}
	MaxMercury();								
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}