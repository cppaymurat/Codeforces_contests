#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, a, b;
	cin >> n >> a >> b;
	if (min(a, b) >= n) {
		cout << "YES\n";
	} else cout << "NO\n";
}
