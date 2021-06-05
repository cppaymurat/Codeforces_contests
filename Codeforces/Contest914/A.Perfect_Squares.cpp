#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<long long> a;
	long long mx = -10000000;
	while(n--)
	{
		long long tmp;
		cin>>tmp;
		if ((int)(sqrt(tmp)) != sqrt(tmp)) mx = max(mx,tmp);
	}
	cout<<mx;
	return 0;
}