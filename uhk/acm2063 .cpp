#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
bool visit[510];
int ar[510][510];
int link[510];
int res, M, N;
bool dfs(int f);
int main()
{
	int i, j, k, u, a, b, n, m;
	while (scanf("%d", &k) != EOF && k)
	{
		scanf("%d %d", &M, &N);
		memset(ar, 0, sizeof(ar));
		memset(link, -1, sizeof(link));
		res = 0;
		for (i = 1; i <= k; i++)
		{
			scanf("%d %d", &a, &b);
			ar[a][b] = 1;
		}
		for (i = 1; i <= M; i++)
		{
			memset(visit, false, sizeof(visit));
			if (dfs(i))
				res++;
		}
		printf("%d\n", res);
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