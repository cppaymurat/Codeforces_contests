#include <bits/stdc++.h>
using namespace std;
int cnt[100005];
int main()
{
	int n;
	cin>>n;
	vector<long long> a;
	long long mx = -10000000;
	while(n--)
	{
		long long tmp;
		cin>>tmp;
		a.push_back(tmp);
		mx = max(mx, tmp);
	}
	int cnt_maxs = 0;
	for(int i = 0; i < a.size(); i++)
	{
		cnt[a[i]]++;
		if (a[i] == mx) cnt_maxs++;
	}
	if (cnt_maxs % 2 == 1) return cout<<"Conan\n",0;
	sort(a.rbegin(),a.rend());
	int pobeda = 1;
	for(int i = 0; i < a.size(); i++)
	{
		if (cnt[a[i]] % 2 == 1) return cout<<"Conan\n",0;
	}
	cout<<"Agasa\n";
	return 0;
}