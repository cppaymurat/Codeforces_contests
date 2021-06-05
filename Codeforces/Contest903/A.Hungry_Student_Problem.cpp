#include <bits/stdc++.h>
using namespace std;
bool can_buy[100];
int main()
{
	for(int i = 1; i <= 100; i++)
	{
		for(int j = 0; j <= 100; j++)
		{
			for(int k = 0; k <= 100; k++)
			{
				if (3 * j + 7 * k == i) can_buy[i] = true;
			}
		}
	}
	int n;
	cin>>n;
	while(n--)
	{
		int x;
		cin>>x;
		if (can_buy[x]) cout<<"YES\n"; else cout<<"NO\n";
	}
	return 0;
}