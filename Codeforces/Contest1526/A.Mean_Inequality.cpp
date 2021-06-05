#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void solve() {
    int n;
    cin >> n;
    n = n * 2;
    deque<int> a(n);
    for(int i = 0; i < n; i += 1) {
        cin >> a[i];
    }
    sort(all(a));
    for(int i = 0; i < n; i += 1) {
        if (i & 1) {
            cout << a.front() << ' ';
            a.pop_front();
        }
        else {
            cout << a.back() << ' ';
            a.pop_back();
        }
    }
    cout << '\n';

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
