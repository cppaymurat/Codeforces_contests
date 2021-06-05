#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int cntNeg = 0;
	int cntPos = 0;
	while(n--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if (a < 0) cntNeg++; else cntPos++;
	}
	//cout<<cntNeg<<" "<<cntPos;
	if (cntNeg <= 1 || cntPos <= 1) return printf("Yes\n"),0;
	printf("No\n");
	return 0;
}