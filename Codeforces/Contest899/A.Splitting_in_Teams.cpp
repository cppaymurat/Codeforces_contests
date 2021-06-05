#include <bits/stdc++.h>
using namespace std;
int a[3];
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int tmp;
		cin>>tmp;
		a[tmp]++;
	}
	int q = min(a[1],a[2]);
	a[1] -= min(a[1],a[2]);
	a[2] -= min(a[1],a[2]);
	cout<<q + (a[1] / 3);
	return 0;
}