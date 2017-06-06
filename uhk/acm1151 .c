#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
bool visit[200];
int ar[200][200];
int leftN[200], rightN[200], res, a;
int link[200];
bool dfs(int f);
int main()
{
	int i, j, k, b, n, m, p, q;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &a, &b);
			memset(ar, 0, sizeof(ar));
			memset(leftN, 0, sizeof(leftN));
			memset(rightN, 0, sizeof(rightN));
			memset(link, -1, sizeof(link));
			res = 0;
			for (i = 1; i <= b; i++)
			{
				scanf("%d %d", &p, &q);
				ar[p][q] = 1;
				leftN[p] = 1;
				rightN[q] = 1;
			}
			for (i = 1; i <= a; i++)
			{
				if (leftN[i])
				{
					memset(visit, false, sizeof(visit));
					if (dfs(i))
						res++;
				}
			}
			printf("%d\n", a - res);
		}
	}
	return 0;
}
bool dfs(int f)
{
	int i, j, k, u;
	for (i = 1; i <= a; i++)
	{
		if (rightN[i] && ar[f][i] && !visit[i])
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
