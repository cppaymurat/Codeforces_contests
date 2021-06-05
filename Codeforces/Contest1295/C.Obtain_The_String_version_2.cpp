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

    string s, t;
    cin >> s >> t;

    map <char, vector <int> > pos;
    for(int i = 0; i < s.length(); i++) {
        pos[s[i]].pb(i);
    }

    int k = t.length();
    string z = "";
    bool ok = 1;
    int cur = 0;
    int sid = -1;
    int ans = 0;
    while(cur < k) {
        char toFind = t[cur];
        if (!pos.count(toFind)) {
            cout << -1 << endl;
            return;
        }
        int prev = sid;
        int id = upper_bound(all(pos[toFind]), sid) - pos[toFind].begin();
        sid = *upper_bound(all(pos[toFind]), sid);
       // cout << sid << ' ' << toFind << ' ' << ans << endl;
      //  cout << id << ' ' << sid << endl;
        if (sid <= prev || id >= pos[toFind].size()) {
            ans++;
            sid = -1;
        } else
    //    cout << sid << ' ' << toFind << ' ' << ans << endl;
        cur++;
        if (cur == k) ans++;
    }

    cout << ans << endl;

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
