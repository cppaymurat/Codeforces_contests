#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

const int INF = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    vector<char> v(n);
    for(int i = 0; i < n; i += 1) {
        cin >> x[i];
    }
    set<int> left[2], right[2];
    unordered_map<int, int> id;
    for(int i = 0; i < n; i += 1) {
        cin >> v[i];
        if (v[i] == 'L') {
            left[x[i] % 2].insert(x[i]);
        } else {
            right[x[i] % 2].insert(x[i]);
        }
        id[x[i]] = i;
    }
    vector<int> res(n, -1);
    vector<int> bonus(n, 0);
    for(int i = 0; i <= 1; i += 1) {
        if (!left[i].empty() && !right[i].empty()) {
            vector<int> del;
            vector<int> rev_right(all(right[i]));
            reverse(all(rev_right));
            for(int x : rev_right) {
                auto it = left[i].upper_bound(x);
                if (it != left[i].end()) {
                    int t = (*it - x) / 2;
                    del.push_back(x);
                    res[id[*it]] = res[id[x]] = t;
                    left[i].erase(it);
                }
            }
            for(int x : del) {
                right[i].erase(x);
            }
        }
        while(left[i].size() > 1) {
            auto it = left[i].begin();
            auto jt = next(it);
            int t = *it + (*jt - *it) / 2;
            res[id[*it]] = res[id[*jt]] = t;
            left[i].erase(it);
            left[i].erase(jt);
        }
        while(right[i].size() > 1) {
            auto it = prev(right[i].end());
            auto jt = prev(it);
            int t = m - *it + (*it - *jt) / 2;
            res[id[*it]] = res[id[*jt]] = t;
            right[i].erase(it);
            right[i].erase(jt);
        }
    }

    for(int i = 0; i <= 1; i += 1) {
        if (left[i].size() == 1 && right[i].size() == 1) {
            int x = *begin(left[i]);
            int y = *begin(right[i]);
            int idx = id[x];
            int idy = id[y];
            int t = max(x, m - y);
            x = abs(x - t);
            y = y + t;
            if (y > m) {
                y -= 2 * (y - m);
            }
            t += abs(y - x) / 2;
            res[idx] = res[idy] = t;
        }
    }

    for(int i = 0; i < n; i += 1) {
        cout << res[i] << ' ';
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
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
