#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	int ans1 = 0;
	int ans2 = 0;
	int k1 = 1;
	int k2 = 1;
	if (a > b)
	while(a > b)
	{
		a--;
		ans1 += k1;
		k1++;
		if (a > b)
		{
			b++;
			ans2 += k2;
			k2++;
		}
	}
	else
	while(a < b)
	{
		a++;
		ans1 += k1;
		k1++;
		if (a < b)
		{
			b--;
			ans2 += k2;
			k2++;
		}
	}
	cout<<ans1+ans2;
	return 0;
}