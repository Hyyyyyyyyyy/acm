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
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 100000 + 100;
const int maxm = 100000 + 100;
vector<ll> G[2010];
ll dp[2010][2010];
ll tail[2010][2010];
void init()
{
	ll i, j, k;
	for (i = 0; i <= 2000; i++)
		G[i].clear();
	for (i = 1; i <= 2000; i++)
	{
		for (j = 1; j*j <= i; j++)
		{
			if (i % j == 0)
			{
				G[i].push_back(j);
				if(i/j != j)
					G[i].push_back(i / j);
			}
		}
	}
	memset(tail, 0, sizeof(tail));
	memset(dp, 0, sizeof(dp));
	for (i = 1; i <= 2001; i++)
		dp[i][1] = i, tail[i][1] = 1;
	for (i = 1; i <= 2001; i++)
		dp[1][i] = 1, tail[1][i] = 1;
	for (i = 2; i <= 2000; i++)
	{
		for (j = 2; j <= 2000; j++)
		{
			dp[i][j] = dp[i - 1][j] % MOD;
			for (k = 0; k < G[i].size(); k++)
			{
				dp[i][j] += tail[G[i][k]][j - 1];
				dp[i][j] %= MOD;
				tail[i][j] += tail[G[i][k]][j - 1];
				tail[i][j] %= MOD;
			}
		}
	}
}
int main()
{
	ll i, j, k, cas, CAS, N, M;
	init();
	while (scanf("%lld", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%lld %lld", &N, &M);
			printf("%lld\n", dp[N][M]);
		}
	}
	return 0;
}