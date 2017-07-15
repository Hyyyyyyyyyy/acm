#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
const int maxn = 20;
const int INF = 1e9;
int N, T, RES;
int visit[maxn];
struct Node
{
	int xue;
	int gong;
};
Node ar[maxn];
void dfs(int id, int xue, int gong, int num, int sum)
{
	int i, j;
	if (sum >= RES)
		return;
	if (num == N)
	{
		RES = min(RES, sum);
		return;
	}
	if (xue - T > 0)
	{
		dfs(id, xue - T, gong, num, sum + gong);
	}
	else
	{
		int doudou = 0;
		for (i = 1; i <= N; i++)
		{
			if (!visit[i])
			{
				visit[i] = 1;
				doudou = 1;
				dfs(i, ar[i].xue, gong - ar[id].gong, num + 1, sum + gong - ar[id].gong);
				visit[i] = 0;
			}
		}
		if (!doudou)
			dfs(id, xue, gong, num + 1, sum);
	}
}
int main()
{
	int i, j, k, u, n, m, s;
	while (scanf("%d %d", &N, &T) != EOF)
	{
		s = 0;
		for (i = 1; i <= N; i++)
		{
			scanf("%d %d", &ar[i].xue, &ar[i].gong);
			s += ar[i].gong;
		}
		memset(visit, 0, sizeof(visit));
		RES = INF;
		for (i = 1; i <= N; i++)
		{
			visit[i] = 1;
			dfs(i, ar[i].xue, s, 0, 0);
			visit[i] = 0;
		}
		printf("%d\n", RES);
	}
	return 0;
}