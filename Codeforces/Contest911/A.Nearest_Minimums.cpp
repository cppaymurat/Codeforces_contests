#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	vector<int> a(n);
	vector<int> pos;
	int mn = 1000000001;
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
		mn = min(mn,a[i]);
	}
	for(int i = 0; i < n; i++)
	{
		if (a[i]==mn) pos.push_back(i+1);
	}
	mn = 1000000;
	for(int i = 1; i < pos.size(); i++)
	{
		if (abs(pos[i-1] -pos[i]) < mn) mn = abs(pos[i-1] -pos[i]);
	}
	cout<<mn;
	return 0;
}