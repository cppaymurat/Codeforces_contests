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

bool normal(string s)
{
	if (s == "great!" || s == "don't think so" || 
		s == "not bad" || s == "don't touch me" ||
		s == "cool")
		return true;
		return false;
}
bool worse(string s)
{
	if (s == "don't even" || s == "are you serious?" || 
	s == "worse" || s == "terrible" || s == "go die in a hole" || s == "no way")
	return true;
	return false;
}
int main()
{
	int cnt = 0;
	for(int i = 0; i < 10; i++)
	{
		cout<<i<<flush<<endl;
		string s;
		getline(cin,s);
		if (s == "no") cnt++;
		if (normal(s))
		{
			return cout<<"normal",0;
		}
		if (worse(s))
		{
			return cout<<"grumpy",0;
		}
	}
	cout<<"IamTheBest";
 	return 0;
}