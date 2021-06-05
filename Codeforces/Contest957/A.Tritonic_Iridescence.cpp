#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define F first
#define S second

const int maxN = 1e5 + 1;
const double PI = acos(-1);

int main()
{
	int n;
	cin>>n;
	string str;
	cin>>str;
	int ques = 0;
	int cnt = 0;
	for(int i = 0; i < n - 1; i++)
	{
		if (str[i] == '?') {
			{
				ques++;
				if (i == 0)
				{
					cnt+=2;
				} else
				{
					if (str[i - 1] == '?') cnt++;
					if (str[i + 1] == '?') cnt++;
					if (str[i - 1] == str[i + 1] && str[i - 1] != '?') cnt+=2;
				}
			}
		}
		if (str[i] == str[i + 1] && str[i] != '?')
		{
			return cout<<"No\n",0;
		}
	}
	if (str[n - 1] == '?') ques++, cnt+=2;
	if (ques == 0)
	{
		return cout<<"No\n",0;
	}
	if (cnt > 1)
	return cout<<"Yes\n",0;
	cout<<"No\n";
 	return 0;
}