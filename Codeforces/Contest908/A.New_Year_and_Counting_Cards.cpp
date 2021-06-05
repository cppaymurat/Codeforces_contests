#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxN = 100005;
bool is_gl(char c)
{
	if (c == 'a' || c == 'e' || c == 'u' || c =='i' || c == 'o') return true; return false;
}
int main() {
	string s;
	cin>>s;
	int cnt = 0;
	for(int i = 0; i < s.length(); i++)
	{
		if (is_gl(s[i])) cnt++;
		if (s[i] >= '0' && s[i] <='9')
		{
			if ((s[i] - 48) % 2 == 1) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}