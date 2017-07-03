#include<string>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int maxn = 110;
const int INF = 1000000000;
int dp[maxn][maxn][maxn];
int ar[maxn][maxn], sa[maxn][maxn];
int N, M, K;
int main()
{
	int i, j, k, u, n, m, a, b;
	while (scanf("%d %d %d", &N, &M, &K) != EOF)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= M; j++)
			{
				scanf("%d", &ar[i][j]);
			}
		}
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= M; j++)
			{
				scanf("%d", &sa[i][j]);
			}
		}
		for (i = 0; i < maxn; i++)
		{
			for (j = 0; j < maxn; j++)
			{
				for (k = 0; k < maxn; k++)
					dp[i][j][k] = -INF;
			}
		}
		dp[1][1][K - sa[1][1]] = ar[1][1];
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= M; j++)
			{
				if (i == 1 && j == 1)
					continue;
				for (k = 1; k <= K; k++)
				{
					if (sa[i][j])
					{
						dp[i][j][k] = max(dp[i - 1][j][k + 1], dp[i][j - 1][k + 1]) + ar[i][j];
					}
					else
					{
						dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k]) + ar[i][j];
					}
				}
			}
		}
		int MAX = -INF;
		int MAXi;
		for (i = K; i > 0; i--)
		{
			if (dp[N][M][i] > MAX)
			{
				MAX = dp[N][M][i];
				MAXi = i;
			}
		}
		if (MAX >= 0 && MAXi > 0)
			printf("%d %d\n", MAXi, MAX);
		else
			printf("-1\n");
	}
	return 0;
}
