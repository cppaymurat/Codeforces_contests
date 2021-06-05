#include <bits/stdc++.h>
using namespace std;
int main()
{
	int l, r, a;
	cin>>l>>r>>a;
	while(l == r && a > 0)
	{
		l++;
		a--;
		if (a == 0) break;
		r++;
		a--;
		if (a == 0) break;
	}
	while(l < r && a)
	{
		l++;
		a--;
	}
		while(l == r && a > 0)
	{
		l++;
		a--;
		if (a == 0) break;
		r++;
		a--;
		if (a == 0) break;
	}
	while(l > r && a)
	{
		r++;
		a--;
	}
		while(l == r && a > 0)
	{
		l++;
		a--;
		if (a == 0) break;
		r++;
		a--;
		if (a == 0) break;
	}
	cout<<min(l,r) * 2;
 	return 0;
}