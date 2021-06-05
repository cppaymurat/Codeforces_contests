#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
string getAns(int a, int b, int c)
{
	if (cnt > 99999) return "";
	string ans = "";
	if (a < b)
	{
	a = a * 10;
	cnt++;
	}
	while(a < b)
	{
		a = a * 10;
		ans += "0";
		cnt++;
	}
	int k = a / b;
	ans += (k + 48);
	cnt++;
	a -= k * b;
	if (a == 0) return ans + "0000000";
	return ans + getAns(a,b,c);
}
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	string ans;
	bool was_bigger;
	if (a % b == 0)
	return cout<<-1,0;
	if (a > b)
	{
		int k = a / b;
		a -= k * b;
	}
	if (a < b)
	{
	ans = ".";
	a = a * 10;
	}
	while(a < b)
	{
		a = a * 10;
		ans += "0";
		cnt++;
	}
	ans += getAns(a,b,c);
//	cout<<ans;
	for(int i = 1; i < ans.length(); i++)
	{
		if (ans[i] == (c + 48)) return cout<<i,0;
	}
	cout<<-1;
	return 0;
}