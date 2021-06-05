#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

struct trie_node {
  bool is_leaf;
  int next[3];
  trie_node() {
    is_leaf = false;
    for(int i = 0; i < 3; i++)
      next[i] = -1;
  }
};

const int N = 3e5 + 5;

trie_node trie[N];

int trie_size = 1;

void trie_add(const string& s) {
  int n = s.size();
  int v = 0;
  for(int i = 0; i < n; i++) {
    char c = s[i] - 'a';
    if (trie[v].next[c] == -1) {
      trie[v].next[c] = trie_size++;
    }
    v = trie[v].next[c];
  }
  trie[v].is_leaf = true;
}

int trie_search(const string& s, int v = 0, int i = 0, int current_bad = 0) {
  if (current_bad > 1 || i > s.size()) {
    return false;
  }
  if (i == s.size()) {
    return trie[v].is_leaf && current_bad == 1;
  }
  int c = s[i] - 'a';
  int ans = 0;
  if (trie[v].next[c] != -1) {
    ans = trie_search(s, trie[v].next[c], i + 1, current_bad);
  }

  for(int j = 0; j < 3; j++) {
    if (j == c) continue;
    if (!ans && trie[v].next[j] != -1 && !current_bad) {
      ans |= trie_search(s, trie[v].next[j], i + 1, current_bad + 1);
    }
  }
  return ans;
}

void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    trie_add(s);
  }
  for(int i = 0; i < m; i++) {
    string s;
    cin >> s;
    if (trie_search(s)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
//  freopen("taskA.in", "r", stdin);
//  freopen("taskA.out", "w", stdout);
  int t = 1;
//  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
