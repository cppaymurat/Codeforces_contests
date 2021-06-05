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

const int maxN = 1e5+5;
const int MOD = 1e9+7;

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int side = 0;
	int x = 0, y = 0;
	int ans = 0;
	vpii coords;
	coords.pb(mp(0,0));
	if (s[0] == 'U') side = 1; else side = 2;
	for(int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'U')
		{
			y++;
		} else
		x++;
		coords.pb(mp(x,y));
	}
	//1 - up, 2 - down
	for(int i = 1; i < coords.size() - 1; i++)
	{
		if (coords[i].F == coords[i].S)
		{
			if (side == 1)
			{
				if (coords[i+1].F > coords[i+1].S) 
				{
					ans++;
					side = 2;
				}
			} else
			{
				if (coords[i+1].F < coords[i+1].S)
				{
					ans++;
					side = 1;
				}
			}
		}
	}
	cout<<ans;
	return 0;	
}