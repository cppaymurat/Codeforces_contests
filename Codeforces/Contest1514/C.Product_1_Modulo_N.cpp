#include <bits/stdc++.h>
#include <stdio.h>
#include <unordered_map>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

#define fr first
#define sc second

const int N = 1e5 + 5;

namespace MATH_CAL {
    int mod;
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

int lp[N];
int pref[N];

void solve() {
    for(int i = 2; i < N; i += 1) {
        if (!lp[i]) {
            lp[i] = i;
        }
        if (lp[i] != i) continue;
        for(int j = i + i; j < N; j += i) {
            if (!lp[j]) {
                lp[j] = lp[i];
            }
        }
    }

    int n;
    cin >> n;

    mod = n;

    int now = 1;
    vector<int> cnt(n, 0);

    for(int i = 2; i < n; i += 1) {
        if (gcd(n, i) != 1) continue;
        now = mul(now, i);
        int j = i;
        while(j > 1) {
            cnt[lp[j]] += 1;
            j /= lp[j];
        }
        if (j > 1) {
            cnt[j] += 1;
        }
    }

    while(now != 1) {
        if (now == 0) {
            int w = n;
            while(w > 1) {
                cnt[lp[w]] -= 1;
                w /= lp[w];
            }
            if (w > 1) {
                cnt[w] -= 1;
            }
            now = mul(now, mod_inv(n));
            continue;
        }
        int w = now;
        while(w > 1) {
            cnt[lp[w]] -= 1;
            w /= lp[w];
        }
        if (w > 1) {
            cnt[w] -= 1;
        }
        int was = now;
        now = mul(now, mod_inv(now));
        if (was == now) {
            break;
        }
        continue;
    }

    vector<int> res;

    for(int i = 1; i < n; i += 1) {
        if (i == 1) {
            res.push_back(i);
            continue;
        }
        int w = i;
        bool bad = 0;
        while(w > 1) {
            cnt[lp[w]] -= 1;
            if (cnt[lp[w]] < 0) {
                bad = 1;
            }
            w /= lp[w];
        }
        if (!bad) {
            res.push_back(i);
        } else {
            w = i;
            while(w > 1) {
                cnt[lp[w]] += 1;
                w /= lp[w];
            }
        }
    }

    cout << res.size() << endl;
    for(int x : res) {
        cout << x << ' ';
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("taskA.in", "r", stdin);
//    freopen("taskA.out", "w", stdout);
    int t = 1;
//    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
