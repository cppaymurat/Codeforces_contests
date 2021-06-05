#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

#define fr first
#define sc second

namespace MATH_CAL {
    const int mod = 1e9 + 7;
    inline ll add(ll a, ll b) { return a + b >= mod ? a + b - mod : a + b; }
    inline ll sub(ll a, ll b) { return a - b < 0 ? a - b + mod : a - b; }
    inline ll mul(ll a, ll b) { return (ll) a * b % mod; }
    inline void Add(ll &a, ll b) { (a += b) >= mod ? a -= mod : 0; }
    inline void Sub(ll &a, ll b) { (a -= b) < 0 ? a += mod : 0; }
    inline ll qpow(ll x, ll n) { ll r = 1; for ( ; n; n /= 2, x = mul(x, x)) if (n & 1) r = mul(r, x); return r; }
    inline ll mod_inv(ll x) { return qpow(x, mod - 2); }
    inline ll gcd(ll a, ll b) {while(b) {a %= b; swap(a, b);} return a;}
    inline ll lcm(ll a, ll b) {return a * b / gcd(a, b);}
} using namespace MATH_CAL;

const int N = 2e5 + 5;

ll fact[N];

ll C(ll n, ll k) {
    return mul(fact[n], mul(mod_inv(fact[n - k]), mod_inv(fact[k])));
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    for(int i = 0; i < n; i += 1) {
        cin >> a[i];
        cnt[a[i]] += 1;
    }
    sort(all(a));
    if (cnt[a[0]] < 2) {
        cout << 0 << endl;
    } else {
        for(int i = 1; i < n; i += 1) {
            if ((a[0] & a[i]) != a[0]) {
                cout << 0 << endl;
                return;
            }
        }
        cout << sub(fact[n], mul(fact[n - 2], mul(2, sub(C(n, 2), C(cnt[a[0]], 2))))) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fact[0] = 1;
    for(int i = 1; i < N; i += 1) {
        fact[i] = mul(fact[i - 1], i);
    }
//    freopen("taskA.in", "r", stdin);
//    freopen("taskA.out", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
