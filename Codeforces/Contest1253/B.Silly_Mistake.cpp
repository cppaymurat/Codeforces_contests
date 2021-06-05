#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define vll vector<ll>
#define ull unsigned ll
#define pii pair<int, int>
#define point pii
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
 
#define isFile 0
#define NAME "taskA"
 
using namespace std;
 
const int maxN = (int)1e6 + 123;
const int MOD = (int)1e9 + 7;
const int INF = 1e9 + 12345;
const int CYCLE = -INF;
 
int dx[] = {1,  0, -1,  0,  1,  1, -1, -1};
int dy[] = {0,  1,  0, -1, -1,  1,  1, -1};
 
void MaxMercury() {
	if (isFile) {
		freopen(NAME".in", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);				
}
namespace MATH_CAL {
	const int mod = (int)1e9 + 7;
	inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
	inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
	inline int mul(int a, int b) { return (ll) a * b % mod; }
	inline void Add(int &a, int b) { (a += b) >= mod ? a -= mod : 0; }
	inline void Sub(int &a, int b) { (a -= b) < 0 ? a += mod : 0; }
	inline int qpow(int x, int n) { int r = 1; for ( ; n; n /= 2, x = mul(x, x)) if (n & 1) r = mul(r, x); return r; }
	inline int mod_inv(int x) { return qpow(x, mod - 2); }
} using namespace MATH_CAL;
int tin[maxN];
int tout[maxN];
void solve() {
	int n;
	cin >> n;
	vi arr(n);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	map<int, int> go;
    map<int, bool> mark;
    bool ok = 1;
    int sum = 0;
    int days = 0;
    int last = 0;
    vi time_in_out;
    for(int i = 0; i < n; i++) {
        if(arr[i] > 0 && !mark[arr[i]]) {
        	sum+=arr[i];
            mark[arr[i]] = 1;
            go[arr[i]]++;
        }
        else if(arr[i] < 0 && mark[-1 * arr[i]]) {
        	sum += arr[i];
            go[-1 * arr[i]]--;
        }
        else {
            ok = 0;
            break;
        }
        if(sum == 0){
        	mark.clear();
        	days++;
        	time_in_out.pb(i + 1 - last);
        	last = i + 1;
        }
    }
    for(auto x : go){
        if(x.S != 0){
            ok = 0;
            break;
        }
    }
    if (ok){
        cout << days << endl;
        for(int i = 0; i < time_in_out.size(); i++) 
			cout << time_in_out[i] << " ";
        
		cout << endl;
    } else {
        cout << -1 << endl;
    }
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
