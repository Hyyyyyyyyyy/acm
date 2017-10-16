#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int INF = 100000000;
const ll MOD = 1e9 + 7;
const int maxn = 30;
int G, B, S;
int ar[maxn][maxn];
int g[maxn];
int dp[1 << 22];
int dfs(int sta, int left, int *StaColor)
{
	if (sta == 0 || left == 0)
		return 0;
	if (dp[sta] != -1)
		return dp[sta];
	int i, j, k, res = 0;
	int tt[10];
	memset(tt, 0, sizeof(tt));
	for (i = 0; i <= B - 1; i++)
	{
		int t = 0;
		if (sta & (1 << i))
		{
			int tmp = sta ^ (1 << i);
			int sum = 0;
			for (j = 1; j <= G; j++)
			{
				tt[j] = (StaColor[j] + ar[i + 1][j]);
				sum += tt[j] / S;
				tt[j] %= S;
			}
			if (sum)
			{
				t = sum + dfs(tmp, left - sum, tt);
			}
			else
			{
				t = left - dfs(tmp, left, tt);
			}
			res = max(res, t);
		}
	}
	dp[sta] = res;
	return res;
}
int main()
{
	int i, j, k, n, m, a, sum;
	while (scanf("%d %d %d", &G, &B, &S) != EOF && G+B+S)
	{
		memset(ar, 0, sizeof(ar));
		memset(g, 0, sizeof(g));
		memset(dp, -1, sizeof(dp));
		for (i = 1; i <= B; i++)
		{
			scanf("%d", &n);
			for (m = 1; m <= n; m++)
			{
				scanf("%d", &a);
				ar[i][a]++;
				g[a]++;
			}
		}
		sum = 0;
		for (i = 1; i <= G; i++)
		{
			sum += g[i] / S;
		}
		int StaColor[10];
		memset(StaColor, 0, sizeof(StaColor));
		int res = dfs((1 << B) - 1, sum, StaColor);
		printf("%d\n", 2 * res - sum);
	}
	return 0;
}
