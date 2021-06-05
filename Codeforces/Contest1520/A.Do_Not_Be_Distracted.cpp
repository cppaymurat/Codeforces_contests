#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack<pair<char, int>> w;
    for(int i = 0; i < s.size(); i += 1) {
        if (w.empty() || w.top().first != s[i]) {
            w.push({s[i], 1});
        } else
        if (w.top().first == s[i]) {
            w.top().second += 1;
        }
    }
    vector<int> cnt(26, 0);
    while(!w.empty()) {
        cnt[w.top().first - 'A'] += 1;
        w.pop();
    }
    for(int i = 0; i < 26; i += 1) {
        if (cnt[i] > 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("taskA.in", "r", stdin);
//    freopen("taskA.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
