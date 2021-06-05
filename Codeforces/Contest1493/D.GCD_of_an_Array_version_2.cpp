#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

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

struct node {
  unordered_map<int, int> w;
  node() {}
};

const int N = 2e5 + 5;

int n, q;

node pre[N];
node t[4 * N];

int a[N];

node add(int val) {
  node to_add;
  for(int i = 2; i * i <= val; i++) {
    if (val % i == 0) {
      int cnt = 0;
      while(val % i == 0) {
        cnt++;
        val /= i;
      }
      to_add.w[i] = cnt;
    }
  }
  if (val > 1) {
    to_add.w[val] = 1;
  }
  return to_add;
}

void precalc() {
  for(int i = 1; i <= 2e5; i++) {
    pre[i] = add(i);
  }
}

node merge(const node& lhs, const node& rhs) {
  node res;
  if (lhs.w.size() < rhs.w.size()) {
    for(auto && [x, y] : lhs.w) {
      if (rhs.w.count(x)) {
        res.w[x] = min(rhs.w.at(x), y);
      }
    }
    return res;
  }
  for(auto && [x, y] : rhs.w) {
    if (lhs.w.count(x)) {
      res.w[x] = min(lhs.w.at(x), y);
    }
  }
  return res;
}

void merge(node& res, const node& lhs, const node& rhs, const node& val) {
  for(auto && [x, y] : val.w) {
    if (lhs.w.count(x) && rhs.w.count(x)) {
      res.w[x] = min(lhs.w.at(x), rhs.w.at(x));
    }
  }
}

void summ(node& lhs, const node& rhs) {
  for(auto && [x, y] : rhs.w) {
    lhs.w[x] += y;
  }
}

void build(int tl, int tr, int v) {
  if (tl == tr) {
    t[v] = pre[a[tl]];
  } else {
    int tm = (tl + tr) >> 1;
    build(tl, tm, v + v + 1);
    build(tm + 1, tr, v + v + 2);
    t[v] = merge(t[v + v + 1], t[v + v + 2]);
  }
}

void update(int pos, const node& val, int v, int tl = 1, int tr = n) {
  if (tl == tr) {
    summ(t[v], val);
  } else {
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
      update(pos, val, v + v + 1, tl, tm);
    } else {
      update(pos, val, v + v + 2, tm + 1, tr);
    }
    merge(t[v], t[v + v + 1], t[v + v + 2], val);
  }
}

ll query() {
  ll res = 1;
  for(auto && [x, y] : t[0].w) {
    res = mul(res, qpow(x, y));
  }
  return res;
}

void solve() {
  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, n, 0);
  ll res = query();
  for(int i = 1; i <= q; i++) {
    int pos, val;
    cin >> pos >> val;
    for(auto && [x, y] : pre[val].w) {
      if (t[0].w.count(x)) {
        res = mul(res, mod_inv(qpow(x, t[0].w[x])));
      }
    }
    update(pos, pre[val], 0);
    for(auto && [x, y] : pre[val].w) {
      if (t[0].w.count(x)) {
        res = mul(res, qpow(x, t[0].w[x]));
      }
    }
    cout << res << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  precalc();
//  freopen("taskA.in", "r", stdin);
//  freopen("taskA.out", "w", stdout);
  int t = 1;
//  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
