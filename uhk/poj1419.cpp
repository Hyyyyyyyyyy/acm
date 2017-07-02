#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 200;
int ar[maxn][maxn];
int stack[maxn][maxn], node[maxn], ans[maxn];   //node 是记录每次dp时的路径，ans是记录RES的路径
int dp[maxn];
int N, M, RES;
void dfs(int dep, int num)
{
	int i, j;
	if (num == 0)
	{
		if (RES < dep)
		{
			RES = dep;
			for (j = 1; j <= dep; j++)
			{
				ans[j] = node[j];
			}
		}
		return;
	}
	for (i = 1; i <= num; i++)
	{
		int u = stack[dep][i];
		if (dep + N - u + 1 <= RES)
			return;
		if (dep + dp[u] <= RES)
			return;
		int top = 0;
		node[dep+1] = u;
		for (j = i + 1; j <= num; j++)
		{
			int v = stack[dep][j];
			if (!ar[u][v])
				stack[dep + 1][++top] = v;
		}
		dfs(dep + 1, top);
	}
}
int main()
{
	int i, j, k, u, n, m, a, b;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &N, &M);
			memset(ar, 0, sizeof(ar));
			memset(dp, 0, sizeof(dp));
			memset(stack, 0, sizeof(stack));
			for (i = 1; i <= M; i++)
			{
				scanf("%d %d", &a, &b);
				ar[a][b] = ar[b][a] = 1;
			}
			RES = 0;
			for (i = N; i >= 1; i--)
			{
				int top = 0;
				node[1] = i;
				for (j = i + 1; j <= N; j++)
				{
					if (!ar[i][j])
						stack[1][++top] = j;
				}
				dfs(1, top);
				dp[i] = RES;
			}
			printf("%d\n", dp[1]);
			for (i = 1; i <= RES; i++)
				printf("%d ", ans[i]);
			putchar('\n');
		}
	}
	return 0;
}