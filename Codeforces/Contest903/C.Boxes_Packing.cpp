#include <bits/stdc++.h>
using namespace std;
bool used[5123];
int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
	{
		int q;
		cin>>a[i];
	}
	int cnt = 0;
	sort(a.begin(),a.end());
	//1 1 2 2 3 3
//	for(int i = 0; i < n; i++)
//	cout<<a[i]<<" ";
//	cout<<endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			if (a[i] < a[j] && !used[j]) {
				cnt++;
			//	cout<<i+1<<"\n";
				used[j] = true;
				break;
			}	
		}
	}
	cout<<n - cnt;
	return 0;
}