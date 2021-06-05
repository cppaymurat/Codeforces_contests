#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define vi vector<int>
#define F first
#define S second
#define pii pair<int,int>
#define vpii vector<pii>
#define vll vector<ll>
#define all(v) v.begin(), v.end()
const int maxN = (int)(1 << 17) + 123;
const int MOD = (int)1e8;
const int INF = (int)1e9;
 
int dx[] = {-1, 1, 0, 0, -1, 1, 1, -1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
	
void MaxMercury() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int gcd(int a, int b) {
	while(b != 0) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}
int a[maxN];
int t[4 * maxN];
void build(int qLeft, int qRight, int v, int op) {
	if (qLeft == qRight) {
		t[v] = a[qLeft];
	} else {
		int leftEnd = qLeft + qRight >> 1;
		int rightBegin = leftEnd + 1;
		build(qLeft, leftEnd, v + v, op ^ 1);
		build(rightBegin, qRight, v + v + 1, op ^ 1);
		if (op) {
			t[v] = t[v + v] | t[v + v + 1];
		} else {
			t[v] = t[v + v] ^ t[v + v + 1];
		}
	}
}
void update(int qLeft, int qRight, int v, int pos, int val, int op) {
	if (qLeft == qRight) {
		t[v] = val;
	} else {
		int leftEnd = qLeft + qRight >> 1;
		int rightBegin = leftEnd + 1;
		if (pos <= leftEnd) {
			update(qLeft, leftEnd, v + v, pos, val, op ^ 1);
		} else {
			update(rightBegin, qRight, v + v + 1, pos, val, op ^ 1);
		}
		if (op) {
			t[v] = t[v + v] | t[v + v + 1];
		} else {
			t[v] = t[v + v] ^ t[v + v + 1];
		}
	}
}
void solve() {
	int N;
	cin >> N;
	int M;
	cin >> M;
	for(int i = 1; i <= (1 << N); i++) {
		cin >> a[i];
	}
	build(1, (1 << N), 1, N & 1);
	for(int i = 1; i <= M; i++) {
		int p, b;
		cin >> p >> b;
		update(1, (1 << N), 1, p, b, N & 1);
		cout << t[1] << endl;
	}
}
int main() {
//	freopen("in.txt" ,"r", stdin);
	MaxMercury();
	int t = 1;
//	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}