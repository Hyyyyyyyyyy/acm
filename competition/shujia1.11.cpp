#include<string>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn = 110;
const int INF = 1000000000;
ll multiply(ll a, ll b, ll mod)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
        {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}
int main()
{
    int i, j, k, u, n, m;
    ll N, M, x, y;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%lld %lld %lld %lld", &N, &M, &x, &y);
            if(x > y)
                swap(x ,y );
            ll res = x * multiply((ll)2, M, N) % N;
            ll res2 = N - res;
            if(res < res2)
                swap(res, res2);
            printf("%lld %lld\n", res, res2);
        }
    }
    return 0;
}