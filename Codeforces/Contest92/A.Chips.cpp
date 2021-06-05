#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1;m > 0;i++) {
		if (m - i < 0) return cout << m, 0;
		m -= i;
		if (i == n) i = 0;
	}
	cout << 0 << endl;
	return 0;
}