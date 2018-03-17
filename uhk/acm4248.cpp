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
const ll inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const ll maxn = 100 + 10;
const ll maxm = 1000000 + 100;
ll dp[maxn][10010];
ll C[10010][maxn];
void init()
{
	ll i, j, k;
	for (i = 0; i <= 10000; i++)
	{
		C[i][0] = 1;
		if (i <= 100)
			C[i][i] = 1;
	}
	for (i = 2; i <= 10000; i++)
	{
		for (j = 1; j < min(i, 101ll); j++)
		{
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
		}
	}
}
int main()
{
	ll i, j, k, N, cas = 1;
	init();
	while (scanf("%lld", &N) != EOF)
	{
		ll sum = 0;
		ll ar;
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		ll res = 0;
		for (i = 1; i <= N; i++)
		{
			scanf("%lld", &ar);
			sum += ar;
			for (k = 0; k <= ar; k++)
			{
				for (j = k; j <= sum; j++)
				{
					dp[i][j] = (dp[i][j] + dp[i - 1][j - k] * C[j][k] % MOD) % MOD;
				}
			}
		}
		for (i = 1; i <= sum; i++)
			res = (res + dp[N][i]) % MOD;
		printf("Case %lld: %lld\n", cas++, res);
	}
	return 0;
}