#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

bool visit[110];
int ar[110][110];
int leftN[110], rightN[110], res, ans, b;
int link[110];
bool dfs(int f);
int main()
{
	int i, j, k, n, m, u, a, p, q, count, cas = 1;
	while (scanf("%d %d %d", &a, &b, &n) != EOF)
	{
		memset(ar, 0, sizeof(ar));
		memset(link, -1, sizeof(link));
		memset(leftN, 0, sizeof(leftN));
		memset(rightN, 0, sizeof(rightN));
		res = 0;
		ans = 0;
		count = 0;
		for (i = 1; i <= n; i++)
		{
			scanf("%d %d", &leftN[i], &rightN[i]);
			ar[leftN[i]][rightN[i]] = 1;
		}
		for (i = 1; i <= a; i++)
		{
			memset(visit, false, sizeof(visit));
			if (dfs(i))
				res++;
		}
		for (i = 1; i <= n; i++)
		{
			ar[leftN[i]][rightN[i]] = 0;
			memset(link, -1, sizeof(link));
			ans = 0;
			for (j = 1; j <= a; j++)
			{
				memset(visit, false, sizeof(visit));
				if (dfs(j))
					ans++;
			}
			if (ans != res)
				count++;
			ar[leftN[i]][rightN[i]] = 1;
		}
		printf("Board %d have %d important blanks for %d chessmen.\n", cas++, count, res);
	}
	return 0;
}
bool dfs(int f)
{
	int i, j, k, u;
	for (i = 1; i <= b; i++)
	{
		if (!visit[i] && ar[f][i])
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