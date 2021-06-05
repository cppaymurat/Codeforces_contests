#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

const int N = 4e5 + 5;

vector<int> g[N];
int col[N];
int tin[N];
int tout[N];
int timer;
int n, m;
ll bit[60];
ll t[4 * N];
ll z[4 * N];
int a[N]; // a[i] - вершина v такая, что tin[v] = i
void dfs(int v, int pr = -1) {
  tin[v] = ++timer;
  a[tin[v]] = v;
  for(int to : g[v]) if (to != pr) {
    dfs(to, v);
  }
  tout[v] = timer;
}

void push(int tl, int tr, int v) {
  if (z[v] != -1) {
    t[v] = z[v];
    if (tl != tr) {
      z[v + v + 1] = z[v];
      z[v + v + 2] = z[v];
    }
    z[v] = -1;
  }
}

void build(int tl, int tr, int v) {
  z[v] = -1;
  if (tl == tr) {
    t[v] = bit[col[a[tl]]];
  } else {
    int tm = (tl + tr) >> 1;
    build(tl, tm, v + v + 1);
    build(tm + 1, tr, v + v + 2);
    t[v] = t[v + v + 1] | t[v + v + 2];
  }
}

ll query(int ql, int qr, int tl, int tr, int v) {
  push(tl, tr, v);
  if (ql > tr || tl > qr)
    return 0;
  if (ql <= tl && tr <= qr) {
    return t[v];
  } else {
    int tm = (tl + tr) >> 1;
    return query(ql, qr, tl, tm, v + v + 1) |
           query(ql, qr, tm + 1, tr, v + v + 2);
  }
}

int query(int v) {
  return __builtin_popcountll(query(tin[v], tout[v], 1, n, 0));
}

void update(int ql, int qr, int tl, int tr, int val, int v) {
  push(tl, tr, v);
  if (ql > tr || tl > qr)
    return;
  if (ql <= tl && tr <= qr) {
    z[v] = bit[val];
    push(tl, tr, v);
  } else {
    int tm = (tl + tr) >> 1;
    update(ql, qr, tl, tm, val, v + v + 1);
    update(ql, qr, tm + 1, tr, val, v + v + 2);
    t[v] = t[v + v + 1] | t[v + v + 2];
  }
}

void update(int v, int c) {
  update(tin[v], tout[v], 1, n, c, 0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for(int i = 0; i < 60; i++) {
    bit[i] = (1ll << i);
  }
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    cin >> col[i];
    col[i]--;
  }
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
  build(1, n, 0);
  for(int i = 1; i <= m; i++) {
    int op;
    cin >> op;
    if (op == 1) {
      int v, c;
      cin >> v >> c;
      c--;
      update(v, c);
    } else {
      int v;
      cin >> v;
      cout << query(v) << endl;
    }
  }
  return 0;
}

