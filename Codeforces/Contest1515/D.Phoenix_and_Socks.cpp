#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

#define OWOW or

const int N = 2e5 + 5;

void solve() {
    int n, lf, rg;
    cin >> n >> lf >> rg;
    unordered_map<int, int> cnt_left, cnt_right;
    for(int i = 0; i < lf; i += 1) {
        int x;
        cin >> x;
        cnt_left[x] += 1;
    }
    for(int i = 0; i < rg; i += 1) {
        int x;
        cin >> x;
        cnt_right[x] += 1;
    }
    int res = 0;
    auto removeGoods = [&] () {
        for(const auto& it : cnt_left) {
            int col = it.first;
            int cnt = it.second;
            if (cnt_right.count(col)) {
                int x = min(cnt_right[col], cnt_left[col]);
                cnt_right[col] -= x;
                cnt_left[col] -= x;
            }
        }
    };

    auto removeOneByOne = [&] () {
        vector<int> meetsOnceLeft,
                    meetsOnceRight;
        for(const auto& it : cnt_left) {
            int col = it.first;
            int cnt = it.second;
            if (cnt % 2 == 1) {
                meetsOnceLeft.push_back(col);
            }
        }
        for(const auto& it : cnt_right) {
            int col = it.first;
            int cnt = it.second;
            if (cnt % 2 == 1) {
                meetsOnceRight.push_back(col);
            }
        }
        while(!meetsOnceLeft.empty() && !meetsOnceRight.empty()) {
            res += 1;
            cnt_left[meetsOnceLeft.back()] -= 1;
            cnt_right[meetsOnceRight.back()] -= 1;
            meetsOnceLeft.pop_back();
            meetsOnceRight.pop_back();
        }
    };

    auto removeOneByOneLeft = [&] () {
        vector<int> meetsOnceLeft,
                    meetsOnceRight;
        for(const auto& it : cnt_left) {
            int col = it.first;
            int cnt = it.second;
            if (cnt % 2 == 1) {
                meetsOnceLeft.push_back(col);
            }
        }
        for(const auto& it : cnt_right) {
            int col = it.first;
            int cnt = it.second;
            for(int i = 0; i < cnt; i += 1) {
                meetsOnceRight.push_back(col);
            }
        }
        while(!meetsOnceLeft.empty() && !meetsOnceRight.empty()) {
            res += 1;
            cnt_left[meetsOnceLeft.back()] -= 1;
            cnt_right[meetsOnceRight.back()] -= 1;
            meetsOnceLeft.pop_back();
            meetsOnceRight.pop_back();
        }
    };

     auto removeOneByOneRight = [&] () {
        vector<int> meetsOnceLeft,
                    meetsOnceRight;
        for(const auto& it : cnt_left) {
            int col = it.first;
            int cnt = it.second;
            for(int i = 0; i < cnt; i += 1) {
                meetsOnceLeft.push_back(col);
            }
        }
        for(const auto& it : cnt_right) {
            int col = it.first;
            int cnt = it.second;
            if (cnt % 2 == 1) {
                meetsOnceRight.push_back(col);
            }
        }
        while(!meetsOnceLeft.empty() && !meetsOnceRight.empty()) {
            res += 1;
            cnt_left[meetsOnceLeft.back()] -= 1;
            cnt_right[meetsOnceRight.back()] -= 1;
            meetsOnceLeft.pop_back();
            meetsOnceRight.pop_back();
        }
    };

    auto removeSameColor = [&] () {
        for(const auto& it : cnt_left) {
            int col = it.first;
            int cnt = it.second;
            if (cnt >= 2) {
                res += cnt / 2;
                cnt %= 2;
            }
            if (cnt) {
                res += 1;
            }
        }

        for(const auto& it : cnt_right) {
            int col = it.first;
            int cnt = it.second;
            if (cnt >= 2) {
                res += cnt / 2;
                cnt %= 2;
            }
            if (cnt) {
                res += 1;
            }
        }
    };

    removeGoods();
    removeOneByOne();
    removeOneByOneLeft();
    removeOneByOneRight();
    removeSameColor();

    cout << res << endl;
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
