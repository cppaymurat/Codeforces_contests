#include <bits/stdc++.h>
    using namespace std;
     
    #define ll long long
    #define pb push_back
    #define mp make_pair
     
    #define F first
    #define S second
     
    #define pii pair<int,int>
    #define vi vector<int>
    #define vll vector<ll>
    #define vpii vector<pii>
    #define pll pair<ll,ll>
     
    const int maxN = (int)1e6 + 123;
    const int MOD = (int)1e9 + 7;
    ll n, m, q;
    ll gcd;
    ll wh[3];
    string check(ll x1, ll y1, ll x2, ll y2) {
    	if ((y1 - 1)/ (wh[x1] / gcd) != (y2 - 1) / (wh[x2] / gcd)) {
    		return "NO";
    	}
    	return "YES";
    }
    void solve() {
    	cin >> n >> m >> q;
    	wh[1] = n;
    	wh[2] = m;
    	gcd = __gcd(n, m);
    	while(q--) {
    		ll x1, y1, x2, y2;
    		cin >> x1 >> y1 >> x2 >> y2;
    		cout << check(x1, y1, x2, y2) << endl;
    	}
    }
    int main() {
    //	freopen("in.txt", "r", stdin);
    	int t = 1;
    //	cin >> t;
    	while(t--) {
    		solve();
    	}
    	return 0;
    }