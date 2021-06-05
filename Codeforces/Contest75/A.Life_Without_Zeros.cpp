#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e5 + 5;
const int MOD = (int)1e9 + 7;
#define ll long long
#define mp make_pair
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>

#define F first
#define S second

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int c = a + b;
	stringstream d;
	stringstream d_, _d, dd, _dd, dd_;
	d << c;
	string s;
	d >> s;
	string s_ = "";
	for(int i = 0; i < s.length(); i++) {
		if (s[i] != '0') s_ += s[i];
	}
	string a_ = "", b_ = "";
	d_ << a;
	d_ >> a_;
	_d << b;
	_d >> b_;
	string _a = "", _b = "";
	for(int i = 0; i < a_.length(); i++) {
		if (a_[i] != '0') {
			_a += a_[i];
		}
	}
	for(int i = 0; i < b_.length(); i++) {
		if (b_[i] != '0') {
			_b += b_[i];
		}
	}
	dd << _a;
	dd >> a;
	dd_ << _b;
	dd_ >> b;
	c = a + b;
	_dd << c;
	_dd >> s;
	if (s != s_) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
	return 0;
}