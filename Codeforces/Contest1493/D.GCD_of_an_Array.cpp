#include <bits/stdc++.h>
using namespace std;
#define ll long long

int mod = 1000000007;


struct node
{
    unordered_map<int, int> m;
};
node M[200005];
void tonode(int n)
{
    int j = n;
    for(int i = 2; i * i <= n; ++i)
    {
        if(n % i == 0)
        {
            int cnt = 0;
            while(n % i == 0)
            {
                ++cnt;
                n /= i;
            }
            M[j].m[i] = cnt;
        }
    }
    if(n > 1) M[j].m[n] = 1;
}

node gcd(const node& a, const node& b)
{
    node nd;
    if(a.m.size() < b.m.size())
    {
        for(auto it = a.m.cbegin(); it != a.m.cend(); ++it)
        {
            if(it->second && b.m.count(it->first))
            {
                nd.m[it->first] = min(it->second, b.m.at(it->first));
            }
        }
    }
    else
    {
        for(auto it = b.m.cbegin(); it != b.m.cend(); ++it)
        {
            if(it->second && a.m.count(it->first))
            {
                nd.m[it->first] = min(it->second, a.m.at(it->first));
            }
        }
    }
    return nd;
}


void gcd2(node &x, const node &a, const node &b, const node &c)
{
    for(auto it = c.m.cbegin(); it != c.m.cend(); ++it)
    {
        if(a.m.count(it->first) && b.m.count(it->first)) x.m[it->first] = min(a.m.at(it->first), b.m.at(it->first));
    }
}

node pref;
struct segtree
{
    vector<node> tree;
    int size, costil;
    void init(int n)
    {
        costil = n;
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2*size);
        size = n;
    }
    void build(vector<int> &a)
    {
        init(a.size());
        build(a, 0, 0, size);
    }
    void build(vector<int> &a, int x, int l, int r)
    {
        if(r - l == 1)
        {
            tree[x] = M[a[l]];
            return;
        }
        int m = l + (r - l)/2;
        build(a, 2*x+1, l, m);
        build(a, 2*x+2, m, r);
        tree[x] = gcd(tree[2*x+1], tree[2*x+2]);
    }
    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }
    void set(int i, int v, int x, int l, int r)
    {
        if(r - l == 1)
        {
            for(auto it = M[v].m.begin(); it != M[v].m.end(); ++it)
            {
                if(tree[0].m.count(it->first)) pref.m[it->first] = tree[0].m[it->first];
                tree[x].m[it->first] += it->second;
            }
            return;
        }
        int m = l + (r - l)/2;
        if(i < m) set(i, v, 2*x+1, l, m);
        else set(i, v, 2*x+2, m, r);
        gcd2(tree[x], tree[2*x+1], tree[2*x+2], M[v]);
    }
};

int binpow(int a, int p)
{
    int b = 1;
    while(p > 0)
    {
        if(p%2==0)
        {
            a = (a*1ll*a)%mod; p /= 2;
        }
        else
        {
            b = (b*1ll*a)%mod; --p;
        }
    }
    return b;
}

ll ans = 1;

int toans(node a)
{
    for(auto it = a.m.begin(); it != a.m.end(); ++it)
    {
        if(it->first > 1 && it->second > 0) ans = (ans*1ll*binpow(it->first, it->second))%mod;
    }
    return ans;
}


int main()
{
//    freopen("taskA.in", "r", stdin);
//    freopen("taskA.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(int i = 1; i <= 2e5; ++i) tonode(i);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    segtree seg; seg.build(a);
    ans = toans(seg.tree[0]);
    while(q--)
    {
        int i, x; cin >> i >> x;
        seg.set(i-1, x);
        for(auto it = M[x].m.begin(); it != M[x].m.end(); ++it)
        {
            ans = (ans*1ll*binpow(it->first, seg.tree[0].m[it->first] - pref.m[it->first]))%mod;
        }
        cout << ans << endl;
    }
    return 0;
}
