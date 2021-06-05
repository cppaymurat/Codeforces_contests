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
	int hh,mm;
	cin>>hh>>mm;
	double H,D,C,N;
	cin>>H>>D>>C>>N;
	double hsave = H;
	double ans1 = 0;
	double ans2 = 0;
	if (hh < 20)
	{
		while(hh < 20)
		{
			mm++;
			H += D;
			if (mm == 60)
			{
				mm = 0;
				hh++;
			}
		}
		if ((int)(H / N) != H / N) H += N;
		if ((int)(hsave / N) != hsave / N) hsave += N;
		ans1 = (int)((double)(H / N)) * 0.8 * C;
		ans2 = (int)((double)(hsave / N)) * C;
		return cout<<min(ans1, ans2),0;
	}
	if (hh >= 20)
	{
				if ((int)(H / N) != H / N) H += N;
		ans1 = (int)((double)(H / N)) * 0.8 * C;
		return cout<<ans1,0;
	}
 	return 0;
}