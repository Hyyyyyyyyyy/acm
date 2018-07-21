#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define foR for
#define for9 for
#define retunr return
#define reutrn return
#define reutnr return
#define retrun return
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 20000000 + 100;
const int maxm = 1000000 + 100;
ll N, V;
ll ar[maxn];
ll sum[maxn];
int check(ll med)
{
    if(med*2-1 > N)
        return 1;
    ll t1 = sum[med];
    ll t2 = sum[N] - sum[N-med+1];
    if(t1+t2 >= V)
        return 0;
    if(med*2 <= N)
    {
        t2 = sum[N] - sum[N-med];
        if(t1+t2 >= V)
            return 0;
    }
    return -1;
}
ll erfen()
{
    ll i, j, k;
    ll L = 1;
    ll R = N;
    ll mid;
    while(L <= R)
    {
        mid = (L + R) / 2;
        if(check(mid) >= 0)
            R = mid-1;
        else
            L = mid+1;
    }
    if(check(L) == 0)
        return ar[L];
    else
        return -1;
}
int main()
{
	ll i, j, k, cas, CAS;
	while (scanf("%lld", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%lld %lld", &N, &V);
			for (i = 1; i <= N; i++)
			{
				scanf("%lld", &ar[i]);
			}
            sort(ar+1, ar+1+N);
            for(i = 1; i <= N; i++)
            {
                sum[i] = sum[i - 1] + ar[i];
            }
            printf("Case #%lld: %lld\n", cas, erfen());
			// ll res = inf;
			// for (i = 1; i <= N; i++)
			// {
			// 	if ((i * 2 - 1 <= N && sum[i * 2 - 1] >= V) || (i * 2 <= N && sum[i * 2] >= V && ar[i] <= ar[i+1]))
			// 	{
			// 		res = min(res, ar[i]);
			// 	}
			// }
			// if (res != inf)
			// 	printf("Case #%lld: %lld\n", cas, res);
			// else
			// 	printf("Case #%lld: -1\n", cas);
		}
	}
	return 0;
}
