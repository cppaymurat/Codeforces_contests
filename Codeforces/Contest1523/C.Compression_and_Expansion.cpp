#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<deque<int>> res;
    deque<int> cur;
    stack<int> levels;
    for(int i = 0; i < n; i += 1) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i += 1) {
        if (a[i] == 1) {
            levels.push(1);
            cur.push_back(1);
        } else {
            if (a[i] == levels.top() + 1) {
                cur.back() += 1;
                levels.top() += 1;
            } else {
                while(!levels.empty() && levels.top() != a[i] - 1) {
                    levels.pop();
                    cur.pop_back();
                }
                assert(!levels.empty());
                levels.top() += 1;
                cur.back() += 1;
            }
        }
        res.push_back(cur);
    }
    for(auto v : res) {
        for(int i = 0; i < v.size(); i += 1) {
            if (i > 0)
                cout << '.';
            cout << v[i];
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("taskA.in", "r", stdin);
//    freopen("taskA.out", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
