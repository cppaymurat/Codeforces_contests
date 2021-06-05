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

int box[1234];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i = 0; i < m; i++)
	{
		int tmp;
		cin>>tmp;
		box[tmp]++;
	}
	cout<<*min_element(box + 1, box + n + 1);
 	return 0;
}