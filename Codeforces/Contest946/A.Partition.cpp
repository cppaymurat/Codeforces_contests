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
	int n;
	cin>>n;
	vi a(n);
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	int s = 0;
	int b = 0;
	for(int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			s += abs(a[i]);	
		} else
		b += a[i];
	}
	cout<<b+s;
	return 0;	
}