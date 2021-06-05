#include <bits/stdc++.h>
using namespace std;
void cout_zeros(int num)
{
	int c = 0;
	while(num > 0)
	num/=10,c++;
	
	if (c == 5) return;
	for(int i = 1; i < 5 - c; i++)
	cout<<0;
}
int main() {
	string s;
	char n[6];
	cin>>s;
	n[1] = s[0];
	n[2] = s[1];
	n[3] = s[2];
	n[4] = s[3];
	n[5] = s[4];
	
	swap(n[3],n[2]);
	swap(n[5],n[3]);
	long long num = (n[5] - 48) + (n[4] - 48) * 10 + (n[3]-48) * 100 + (n[2] - 48) * 1000 + (n[1] - 48)*10000;
	long long ans = num * num;
	ans = ans % 100000;
	ans = ans * num;
	ans = ans % 100000;
	ans = ans * num;
	ans = ans % 100000;
	ans = ans * num;
	ans = ans % 100000;
	cout<<ans;
	cout_zeros(ans);
	return 0;
}