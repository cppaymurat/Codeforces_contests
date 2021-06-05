#include <bits/stdc++.h>
using namespace std;
int turnir[260][9];
int wons(int fp, int sp, int b, int c)
{
	if (b > c) swap(b, c);
	if (fp == b && sp == c) return 1228;
	if (fp == b || fp == c)
	return fp;
	return sp;
}
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if (b <= a / 2 && c > a / 2)
	{
		return cout<<"Final!",0;
	} else
	if (b > a / 2 && c <= a / 2){
		return cout<<"Final!",0;
	}
	int rounds = 1;
	if (b > c) swap(b, c);
    if(b == 1 && c == a)
    {
    	return cout<< a / 4 , 0;	
    }
    vector<int> graph;
    vector<int> players(257);
    for(int i = 1; i <= 256; i++)
    {
    	players[i] = i;
    }
    int ap = a;
    while(ap > 2)
    {
    	vector<int> newPlayers(256);
    	int j = 1;
		for(int i = 1; i <= players.size(); i+=2)
		{
			newPlayers[j] = wons(players[i],players[i+1],b,c);
			j++;
		}
		for(int i = 1; i <= ap / 2; i++)
		{
			if (newPlayers[i] == 1228) return cout<<rounds,0;
		}
		players = newPlayers;
		rounds++;
		ap/=2;
	}
 	return 0;
}