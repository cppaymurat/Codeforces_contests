#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

void generate_tests() {
    int n = rand() % 30 + 1;
    string s = "";
    string alphabet = "01?";
    for(int i = 0; i < n; i += 1) {
        s += alphabet[rand() % 3];
    }
    cout << s << endl;
}

void slow() {
    string s;
    cin >> s;
    function<bool(string)> good = [] (string t) {
        vector<bool> one(2, false);
        vector<bool> zero(2, false);
        for(int i = 0; i < t.size(); i += 1) {
            if (t[i] == '0') {
                zero[i % 2] = 1;
            }
            if (t[i] == '1') {
                one[i % 2] = 1;
            }
        }
        if (one[0] && one[1]) return false;
        if (zero[0] && zero[1]) return false;
        if (one[0] && zero[0]) return false;
        if (one[1] && zero[1]) return false;
        return true;
    };
    int n = s.size();
    int ans = 0;
    for(int len = 1; len <= n; len += 1) {
        for(int j = 0; j + len <= n; j += 1) {
            if (good(s.substr(j, len))) {
                ans += 1;
            }
        }
    }
    cout << ans << endl;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> zero(2);
    vector<int> one(2);
    auto good = [&] () {
        if (one[0] && one[1]) return false;
        if (zero[0] && zero[1]) return false;
        if (one[0] && zero[0]) return false;
        if (one[1] && zero[1]) return false;
        return true;
    };
    long long result = 0;
    for(int l = 0, r = 0, i = 0; i < n; i += 1, r += 1) {
        if (s[i] == '0') {
            zero[i % 2] += 1;
        } else
        if (s[i] == '1') {
            one[i % 2] += 1;
        }
        if (good()) {
            result += r - l + 1;
        } else {
            while(l < r) {
                if (s[l] == '0') {
                    zero[l % 2] -= 1;
                } else
                if (s[l] == '1') {
                    one[l % 2] -= 1;
                }
                l += 1;
                if (good()) {
                    result += r - l + 1;
                    break;
                }
            }
        }
    }
    cout << result << endl;
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
//        generate_tests();
        solve();
//        slow();
    }
    return 0;
}
