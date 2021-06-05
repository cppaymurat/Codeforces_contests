#include <bits/stdc++.h>
using namespace std;
const int maxN = 200005;
int main()
{
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i = 0; i < m; i++)
	{
		int l,r;
		char c1,c2;
		cin>>l>>r>>c1>>c2;
		l--;
		r--;
		for(int j = l; j <= r; j++)
		{
			if (s[j]==c1) s[j] = c2;
		}
	}
	cout<<s;
	return 0;
}