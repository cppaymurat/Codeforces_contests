#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if (n < 5) return cout<<0<<endl,0;
	if (n%10==0) return cout<<n<<endl,0;
	if (n%10 < 5) return cout<<n/10<<0<<endl,0;
	return cout<<n/10 + 1<<0<<endl,0;
	return 0;
}