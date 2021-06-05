#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define vll vector<ll>
#define F first
#define S second

const int maxN = 305;
const int MOD = 1e9+7;

int main()
{
	unsigned ll a,b;
	cin>>a>>b;
	while(1)
	{
		if (a == 0 || b == 0)
		break;
		if (a >= 2 * b)
		{
			a = a % (2 * b);
			continue;
		} else
		if (b >= 2 * a)
		{
			b = b % (2 * a);
			continue;
		} else
		break;
	}
	cout<<a<<" "<<b;
	return 0;	
}