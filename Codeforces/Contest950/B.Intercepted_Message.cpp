#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n),b(m);
	vector<int> pref_a(n, 0);
	vector<int> pref_b(m, 0);
	cin>>a[0];
	pref_a[0] = a[0];
	set<int> xD;
	xD.insert(pref_a[0]);
	for(int i = 1; i < n; i++)
	{
		cin>>a[i];
		pref_a[i] += a[i] + pref_a[i - 1];
		xD.insert(pref_a[i]);
	}
	cin>>b[0];
	pref_b[0] = b[0];
	xD.insert(pref_b[0]);
	for(int j = 1; j < m; j++)
	{
		cin>>b[j];
		pref_b[j] += b[j] + pref_b[j - 1];
		xD.insert(pref_b[j]);
	}
	cout<<n + m - xD.size();
 	return 0;
}