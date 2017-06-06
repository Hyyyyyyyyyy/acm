#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
bool visit[1010];
int ar[1010][1010];
int res, n;
int link[1010];
bool dfs(int f);
int main()
{
	int i, j, k, u, m, p, q;
	while (scanf("%d", &n) != EOF)
	{
		memset(ar, 0, sizeof(ar));
		memset(link, -1, sizeof(link));
		res = 0;
		for (m = 0; m < n; m++)
		{
			scanf("%d: (%d)", &i, &j);
			for (u = 1; u <= j; u++)
			{
				scanf("%d", &p);
				ar[i][p] = 1;
			}
		}
		for (i = 0; i < n; i++)
		{
			memset(visit, false, sizeof(visit));
			if (dfs(i))
				res++;
		}
		printf("%d\n", n - res/2);
	}
	return 0;
}
bool dfs(int f)
{
	int i, j, k, u;
	for (i = 0; i < n; i++)
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
