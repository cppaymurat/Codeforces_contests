#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	vector<pair<string, string> > NIP;
	vector<pair<string, string> > CIP;
	for(int i = 0; i < n; i++)
	{
		string a,b;
		cin>>a>>b;
		b += ';';
		NIP.push_back(make_pair(a,b));
	}
	for(int j = 0; j < m; j++)
	{
		string a,b;
		cin>>a>>b;
		cout<<a<<" "<<b<<" #";
		for(int i = 0; i < n; i++)
		{
			if (b == NIP[i].second) 
			{
			cout<<NIP[i].first<<endl;
			break;
			}
		}
	}
	
	return 0;
}