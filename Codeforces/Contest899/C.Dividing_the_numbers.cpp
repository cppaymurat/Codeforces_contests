#include <bits/stdc++.h>
using namespace std;
int pref[60000 * 5];
int main()
{
	int n;
	cin>>n;
	int s1 = 0;
	vector<int> f;
	int s2 = 0;
    for (int i = n; i >= 1; --i) {
        if (s1 < s2) s1+=i, f.push_back(i); else s2+=i;
    }
	cout<<abs(s1-s2)<<endl;
	cout<<f.size()<<" ";
	for(int i = 0; i < f.size(); i++)
	{
		cout<<f[i]<<" ";
	}
	return 0;
}