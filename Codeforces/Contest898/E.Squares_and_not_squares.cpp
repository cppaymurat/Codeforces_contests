#include <bits/stdc++.h>
using namespace std;
#define maxN 234567
struct abe
{
       int alpha;
	   int beta;
	   int eps;
};
long long res;
abe a[maxN];
int d_sq, d_not_sq;
abe b[maxN];
int n, cur;
bool sq_l(int x)
{
     int tmp = int(sqrt(x));
     if (tmp * tmp == x) return true;
     return false;
}
int alpha_l(int x)
{
    int tmp = int(sqrt(x));
    if (tmp * tmp == x) return 0;
    return min(x - tmp * tmp, (tmp + 1) * (tmp + 1) - x);
}
int beta_l(int x)
{
    int tmp = int(sqrt(x));
    if (tmp * tmp < x) return 0;
    int d1, d2;
    d1 = 0; d2 = 0;
    int tx;
    tx = x;
    while (sq_l(tx))
    {
          tx -= 1;
          if (tx < 0)
          {
             d1 = 100000;
             break;
          }
          d1 += 1;
    }
    tx = x;
    while (sq_l(tx))
    {
          tx++;
          d2++;
    }
    return min(d1, d2);
}
bool cmp1(abe x, abe y)
{
     return x.alpha < y.alpha;
}
bool cmp2(abe x, abe y)
{
     return x.beta < y.beta;
}
int main()
{
    cin >> n;
    d_sq = d_not_sq = 0;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i].eps;
        a[i].alpha = alpha_l(a[i].eps);
        if (a[i].alpha == 0) d_sq += 1;
        else d_not_sq += 1;
        a[i].beta = beta_l(a[i].eps);
    }
    if (d_sq == d_not_sq) cout << 0;
    else
    {
        if (d_sq < n / 2)
        {
           cur = 0;
           for (int i = 1; i <= n; i++)
               if (a[i].alpha > 0)
               {
                  cur += 1;
                  b[cur] = a[i];
               }
           sort(b + 1, b + d_not_sq + 1, cmp1);
           res = 0;
           for (int i = 1; i <= n / 2 - d_sq; i++) 
		   res += b[i].alpha;
        }
        else
        {
            cur = 0;
            for (int i = 1; i <= n; i++)
                if (a[i].alpha == 0)
                {
                   cur += 1;
                   b[cur] = a[i];
                }
            sort(b + 1, b + d_sq + 1, cmp2);
            res = 0;
            for (int i = 1; i <= d_sq - n / 2; i++) 
			res += b[i].beta;
        }
        cout << res;
    }
    return 0;
}