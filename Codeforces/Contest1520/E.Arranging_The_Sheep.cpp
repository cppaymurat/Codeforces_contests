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
    vector<ll> pref(n, 0);
    vector<ll> cnt(n, 0);
    for(int i = 0; i < n; i += 1) {
        ll w = 0, f = 0;
        if (i > 0) {
            w = pref[i - 1];
            f = cnt[i - 1];
        }
        if (s[i] == '*') {
            pref[i] = w + i + 1;
            cnt[i] = f + 1;
        } else {
            pref[i] = w;
            cnt[i] = f;
        }
    }
    auto get = [&] (int l, int r) {
        if (l > r)
            return 0ll;

        if (l == 0) {
            return pref[r];
        }
        return pref[r] - pref[l - 1];
    };

    auto get_cnt = [&] (int l, int r) {
        if (l > r)
            return 0ll;

        if (l == 0) {
            return cnt[r];
        }
        return cnt[r] - cnt[l - 1];
    };

    auto f = [] (int x) {
        return x * 1ll * (x + 1) / 2;
    };

    auto calc = [&] (int x) {
        ll before = get_cnt(0, x - 1);
        ll after = get_cnt(x + 1, n - 1);
        ll before_sum = get(0, x - 1);
        ll after_sum = get(x + 1, n - 1);
        ll res = before * 1ll * (x + 1) - before_sum - f(before);
        res += after_sum - after * 1ll * (x + 1) - f(after);
        if (s[x] != '*') {
            res += min(before, after);
        }
        return res;
    };

    ll ans = 1e18;

    for(int i = 0; i < n; i += 1) {
        ans = min(ans, calc(i));
    }

    cout << ans << endl;
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
