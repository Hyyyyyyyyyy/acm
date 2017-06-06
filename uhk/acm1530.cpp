#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 100000000;
const int maxn = 60;
int ar[maxn][maxn];
int dp[maxn], stack[maxn][maxn];
int N, RES;
void dfs(int dep, int num)
{
	int i, j, u, v;
	if (num == 0)
	{
		if (RES < dep)
			RES = dep;
		return;
	}
	if (dep + num <= RES)
		return;
	for (i = 0; i < num; i++)
	{
		u = stack[dep][i];
		if (dep + dp[u] <= RES)
			continue;
		if (dep + N - u + 1 <= RES)
			continue;
		int top = 0;
		for (j = i + 1; j < num; j++)
		{
			v = stack[dep][j];
			if (ar[u][v])
				stack[dep + 1][top++] = v;
		}
		dfs(dep + 1, top);
	}
}
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &N) != EOF && N)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				scanf("%d", &ar[i][j]);
			}
		}
		dp[N] = 1;
		RES = 1;
		for (i = N - 1; i >= 1; i--)
		{
			int top = 0;
			for (j = 1; j <= N; j++)
				if (ar[i][j])
					stack[1][top++] = j;
			dfs(1, top);
			dp[i] = RES;
		}
		printf("%d\n", RES);
	}
	return 0;
}