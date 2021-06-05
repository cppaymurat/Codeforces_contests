#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	cin>>a;
	int cnt = 0;
	for(int i = 0; i < a.length(); i++)
	{
		if (a[i]=='Q')
		for(int j = i+1; j < a.length(); j++)
		{
			if (a[j]=='A')
			for(int k = j+1; k < a.length(); k++)
			{
				if (a[k]=='Q') cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}