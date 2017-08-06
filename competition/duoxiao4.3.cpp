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
typedef unsigned long long ll;
const int maxn = 1000000 + 10;
const ll MOD = 998244353;
// void init(__int64 n)//求一个数的质因子
// {
//     __int64 i;
//     num=0;
//     for(i=2;i*i<=n;i++)
//     {
//         if(n%i==0)
//         {
//             a[num++]=i;
//             while(n%i==0)
//                 n=n/i;
//         }
//     }
//     if(n>1)//这里要记得
//         a[num++]=n;
// }
int main()
{
	ll i, j, k, n, m, L, R, K;
	while (scanf("%lld", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lld %lld %lld", &L, &R, &K);
			ll res = 0;
			for (i = L; i <= R; i++)
			{
				if (i == 1)
				{
					res++;
					res %= MOD;
					continue;
				}
				ll t = i;
				ll tt = 1;
				for (j = 2; j <= i; j++)
				{
					if (i % j == 0)
					{
						ll a = 0;
						while (i % j == 0)
						{
							i /= j;
							a++;
						}
						tt = (a * K + 1) % MOD * tt % MOD;
					}
				}
				res = (res + tt) % MOD;
				i = t;
			}
			printf("%lld\n", res);
		}
	}
	return 0;
}