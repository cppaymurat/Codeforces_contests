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
	int cnt = 0;
	for(int i = 1; i < n; i++)
	{
		if ((n - i) % i == 0) cnt++;
	}
	cout<<cnt;
	return 0;	
}