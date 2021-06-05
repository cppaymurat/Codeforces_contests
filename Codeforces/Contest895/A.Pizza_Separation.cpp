#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define vi vector<int>
int getmin(int mn, vector<int> piz, int n)
{
	for(int k = 0; k < n; k++)
	{
	for(int i = 0 + k; i < n + k; i++)
	{
		int summ1 = 0;
		for(int j = 0 + k; j < i + k; j++)
		{
			summ1 += piz[j];
		}
		int summ2 = 0;
		for(int j = i + k; j < n + k; j++)
		{
			summ2 += piz[j];
		}
		mn = min(mn,abs(summ1-summ2));
	//	cout<<summ1<<" "<<summ2<<endl;
		if (mn == 0) return 0;
	}
		}
	return mn;
}
int main()
{
	int n;
	scanf("%d",&n);
	vector<int> piz(n);
	int s2 = 0;
	for(int i = 0; i < n; i++)
	{
		cin>>piz[i];
		s2+=piz[i];
	}
	for(int j = 0; j < n; j++)
	{
		piz.push_back(piz[j]);
	}
	int mn = 360;
	mn = min(getmin(mn,piz,n),mn);
	cout<<mn;
	return 0;
}