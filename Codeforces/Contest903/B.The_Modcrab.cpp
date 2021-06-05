#include <bits/stdc++.h>
using namespace std;
void attack()
{
	cout<<"STRIKE"<<endl;
}
void defence()
{
	cout<<"HEAL"<<endl;
}
int main()
{
	int h1, a1, c, h2, a2;
	cin>>h1>>a1>>c;
	cin>>h2>>a2;
	vector<int> com;
	int needToBit = (int)((double)(h2 / a1));
	if (h2 <= a1){
		cout<<1<<endl;
		attack();
		return 0;
	}
	while (h1 <= a2)
	{
		com.push_back(2);
		h1 += c;
		h1 -= a2;
	}
	while(h2 > 0)
	{
		while (h1 <= a2 && h2 - a1 > 0)
		{
			com.push_back(2);
			h1 += c;
			h1 -= a2;
		}
			com.push_back(1);
			h2 -= a1;
			if (h2 <= 0) break;
			h1 -= a2;
	}
	cout<<com.size()<<endl;
	for(int i = 0; i < com.size(); i++)
	if (com[i]==2) defence(); else attack();
	return 0;
}