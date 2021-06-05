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
ll fib[maxN];
void solve() {
	fib[1] = 1;
	fib[2] = 1;
	for(int i = 3; i <= 100005; i++) {
		fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
	}
	int n, m;
	cin >> n >> m;
	cout << 2 * 1ll * (fib[n + 1] + fib[1 + m] - 1) % MOD << endl;
}
int main() {
	MaxMercury();								
	int t = 1;
//	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}