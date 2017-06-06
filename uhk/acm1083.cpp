#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
bool visit[310];
int link[310];
int ar[110][310];
int res, P, N;
bool dfs(int f);
int main()
{
	int i, j, u, n, m, a, b, k, p;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &P, &N);
			memset(ar, 0, sizeof(ar));
			memset(link, -1, sizeof(link));
			res = 0;
			for (i = 1; i <= P; i++)
			{
				scanf("%d", &k);
				for (j = 1; j <= k; j++)
				{
					scanf("%d", &p);
					ar[i][p] = 1;
				}
			}
			for (i = 1; i <= P; i++)
			{
				memset(visit, false, sizeof(visit));
				if (dfs(i))
					res++;
			}
			if (res == P)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}
bool dfs(int f)
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		if (ar[f][i] && !visit[i])
		{
			visit[i] = true;
			if (link[i] == -1 || dfs(link[i]))
			{
				link[i] = f;
				return true;
			}
		}
	}
	return false;
}