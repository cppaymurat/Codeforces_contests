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
     
    const int maxN = (int)2e5 + 123;
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
     
    void solve() {
   		string s;
   		cin >> s;
   		vector<string> words;
   		string word = "";
   		for(int i = 0; i < s.length(); i++) {
   			if (s[i] == ',' || s[i] == ';') {
   				words.pb(word);
   				word = "";
   			} else word += s[i];
   		} 
   		if (word.length() || s[s.length() - 1] == ',' || s[s.length() - 1] == ';') words.pb(word);
   		string s1 = "";
   		string s2 = "";
   		for(auto &i : words) {
   			int cnt = 0;
   			for(int j = 0; j < i.length(); j++) {
   				if (i[j] >= '0' && i[j] <= '9') {
   					cnt++;
   				}
   			}
   			if (cnt < i.length() || i.length() == 0) {
   				s2 += i + ",";
   			} else {
   				int k = 0;
   				while(k < i.length() && i[k] == '0') k++;
   				if (!k) s1 += i + ","; else 
   				if (k == 1 && i.length() == 1) s1 += i + ","; else
   				s2 += i +",";
   			}
   		}
   		if (!s1.length()) {
   			cout << "-" << endl;
   		} else {
   			cout << "\"" << s1.substr(0, s1.length() - 1) << "\"" << endl;
   		}
   		if (!s2.length()) {
   			cout << "-" << endl;
   		} else {
   			cout << "\"" << s2.substr(0, s2.length() - 1) << "\"" << endl;
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