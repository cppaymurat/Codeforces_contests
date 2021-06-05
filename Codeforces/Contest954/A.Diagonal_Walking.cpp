#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	string str;
	cin>>n;
	cin>>str;
	string save = str;
	int k = str.find("UR");
	int c = 0;
	int ans1 = n;
	int ans2 = n;
	for(int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'U' && str[i + 1] == 'R' && i + 1 < str.length())
		{
			ans1--;
			i++;
		} else
		if (str[i] == 'R' && str[i + 1] == 'U' && i + 1 < str.length())
		{
			ans1--;
			i++;
		}
	}
	cout<<ans1;
 	return 0;
}