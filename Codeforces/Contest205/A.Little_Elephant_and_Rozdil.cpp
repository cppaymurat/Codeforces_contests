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
	int n;
	cin >> n;
	map<int,int> q;
	map<int,int> num;
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		q[t]++;
		num[t] = i + 1;
	}
	if ((*q.begin()).second > 1) return cout << "Still Rozdil\n", 0;
	cout << num[(*q.begin()).first] << endl;
	return 0;
}