#include <bits/stdc++.h>
using namespace std;
int matrix[100][100];
int main() {
	int r, c;
	cin >> r >> c;
	for(int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < s.length(); j++) {
			if (s[j] == '.') {
				matrix[i][j] = 1;
			} else matrix[i][j] = -1;
		}
	}
	int ans = 0;
	for(int i = 0; i < r; i++) {
		int cnt = 0;
		int d = 0;
		for(int j = 0; j < c; j++) {
			if (matrix[i][j] >= 0) {
				cnt++;
				d += matrix[i][j];
			}
		}
		if (cnt == c) {
			ans += d;
			for(int j = 0; j < c; j++) {
				if (matrix[i][j] > 0) {
					matrix[i][j] = 0;
				}
			}
		}
	}
	for(int i = 0; i < c; i++) {
		int d = 0;
		int cnt = 0;
		for(int j = 0; j < r; j++) {
			if (matrix[j][i] >= 0) {
				d += matrix[j][i];
				cnt++;
			}
		}
		if (cnt == r) {
			ans += d;
			for(int j = 0; j < r; j++) {
				if (matrix[j][i] > 0) {
					matrix[j][i] = 0;
				}
			}
		}
	}
	cout << ans;
	return 0;
}