#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	int cnt = 0;
	while(n > 0)
	{
		if (n % b == 0) 
		{
			cout<<"YES\n";
			return cout<< cnt << " " << n / b << endl,0;
		}
		if (n % a == 0)
		{
			cout<<"YES\n";
			return cout<< n / a << " " << cnt << endl,0;
		}
		n -= a;
		cnt++;
	}
	cout<<"NO\n";
	return 0;
}