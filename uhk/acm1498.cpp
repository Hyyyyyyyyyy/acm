#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
bool visit[110];
int ar[110][110];
int sa[110];
int res, a, b;
int link[110];
bool dfs(int f, int g);
int main()
{
	int i, j, k, u, n, m, p, q, cnt;
	while (scanf("%d %d", &a, &b) != EOF && (a || b))
	{
		for (i = 1; i <= a; i++)
		{
			for (j = 1; j <= a; j++)
			{
				scanf("%d", &ar[i][j]);
			}
		}
		cnt = 0;
		for (u = 1; u <= 100; u++)
		{
			memset(link, -1, sizeof(link));
			res = 0;
			for (i = 1; i <= a; i++)
			{
				memset(visit, false, sizeof(visit));
				if (dfs(i, u))
					res++;
			}
			if (res > b)
				sa[cnt++] = u;
		}
		if (!cnt)
			printf("-1\n");
		else
		{
			for (i = 0; i < cnt; i++)
			{
				if (i == 0)
					printf("%d", sa[i]);
				else
					printf(" %d", sa[i]);
			}
			putchar('\n');
		}
	}
	return 0;
}
bool dfs(int f, int g)
{
	int i, j, k, u;
	for (i = 1; i <= a; i++)
	{
		if (ar[f][i] == g && !visit[i])
		{
			visit[i] = true;
			if (link[i] == -1 || dfs(link[i], g))
			{
				link[i] = f;
				return true;
			}
		}
	}
	return false;
}