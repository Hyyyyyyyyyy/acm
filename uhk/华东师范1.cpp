#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
ll gcd(ll x,ll y)
{
    ll t;
    while(y)
    {
        t=x%y;
        x=y;
        y=t;
    }
    return  x;
}
int main()
{
    ll i, j, k, u, n, m, x;
    while(scanf("%lld %lld", &x, &n) != EOF)
    {
        for(m = 2; m <= n; m++)
        {
            printf("%lld\n", m / gcd(x, m));
        }
    }
    return 0;
}