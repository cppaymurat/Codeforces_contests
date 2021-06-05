#include <bits/stdc++.h>

#define pb push_back
#define fr first
#define sc second
#define all(x) x.begin(), x.end()
#define skip continue
#define NAME "taskA"
#define isFile 0
using namespace std;

void faster() {
    if (isFile) {
        freopen(NAME".in", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}

void solve() {

    int n;
    cin >> n;
    if (n % 2 == 0) {
        for(int i = 1; i <= n / 2; i++) cout << 1;
        cout << endl;
        return;
    }

    cout << 7;
    n -= 3;
    for(int i = 1; i <= n / 2; i++) cout << 1;

    cout << endl;
}

signed main() {
    faster();
    int t;
    cin >> t;
    while(t--) {
		solve();
	}
    return 0;
}
