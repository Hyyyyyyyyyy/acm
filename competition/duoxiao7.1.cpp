#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
const int INF = 2147483640;
const double eps = 1e-7;
typedef long long ll;
const ll MOD = 1000000007;
const int maxn = 200000+100;
ll ar[maxn], sa[maxn];
long long MUL(long long a, long long b)
{
	long long res = 1;
	while (b)
	{
		if (b & 1)
		{
			res = (res * a);
		}
		a = (a * a);
		b >>= 1;
	}
	return res;
}
int main()
{
    int i, j, k, u, n, m, N, M;
    while(scanf("%lld %lld", &N, &M) != EOF)
    {
        for(i = 1; i <= N; i++)
        {
            scanf("%lld", &ar[i]);
        }
        ll t = N;
        ll cnt = 0;
        while(t)
        {
            t >>= 1;
            cnt++;
        }
        ll tt = M % MUL(2ll, cnt);
        for(k = 1; k <= tt; k++)
        {
            if(k != 1)
            {
                for(j = 1; j <= N; j++)
                    ar[j] = sa[j];
            }
            for(i = 1; i <= N; i++)
            {
                ll res = 0;
                for(j = 1; j <= i; j++)
                {
                    res ^= ar[j];
                }
                sa[i] = res;
            }
        }
        for(i = 1; i <= N; i++)
            printf("%lld ", sa[i]);
        putchar('\n');
    }
    return 0;
}