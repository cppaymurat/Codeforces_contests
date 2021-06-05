#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define ml make_laser
#define vi vector<int>
#define F first
#define S second

const int maxN = 1e5 + 1;
const double PI = acos(-1);

int main()
{
	int n;
	cin>>n;
	int tmp;
	cin>>tmp;
	for(int i = 0; i < n - 1; i++)
	{
		int a;
		cin>>a;
		if (abs(tmp - a) >= 2) return cout<<"NO\n",0;
		tmp = a;
	}
	cout<<"YES\n";
 	return 0;
}