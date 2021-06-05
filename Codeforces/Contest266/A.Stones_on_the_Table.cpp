#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	for(int i = 1; i < s.length(); i++) {
		if (s[i - 1] == s[i]) ans++;
	}
	cout << ans << endl;
	return 0;
}