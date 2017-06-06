#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = 100000000;
int ar[20][20], vex[20];
int visit[20], tem[20], res[20], dist[20];
int n, m;
double MIN;
void dfs(int f, int num);
int prime(int f);
int main()
{
	int i, j, k, u;
	while (scanf("%d %d", &n, &m) != EOF && (n + m))
	{
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &vex[i]);
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				scanf("%d", &ar[i][j]);
			}
		}
		MIN = 1.0*MAX;
		for (i = 1; i <= n; i++)
		{
			tem[1] = i;
			dfs(i, 1);
		}
		for (i = 1; i < m; i++)
		{
			printf("%d ", res[i]);
		}
		printf("%d\n", res[m]);
	}
	return 0;
}
int prime(int f)
{
	int i, j, k, Min, pos, ans = 0;
	memset(visit, 0, sizeof(visit));
	for (i = 1; i < m; i++)
		dist[tem[i]] = ar[f][tem[i]];
	visit[f] = 1;
	for (i = 1; i < m; i++)
	{
		Min = MAX;
		pos = -1;
		for (j = 1; j <= m; j++)
		{
			if (Min > dist[tem[j]] && !visit[tem[j]])
			{
				Min = dist[tem[j]];
				pos = tem[j];
			}
		}
		if (Min == MAX)
			return -1;
		visit[pos] = 1;
		ans += Min;
		for (j = 1; j <= m; j++)
		{
			if (!visit[tem[j]] && dist[tem[j]] > ar[pos][tem[j]])
			{
				dist[tem[j]] = ar[pos][tem[j]];
			}
		}
	}
	return ans;
}
void dfs(int f, int num)
{
	int i, j, k;
	double ans = 0, sumv = 0, sume = 0;
	if (num == m)
	{
		int cnt = 1;
		for (i = 1; i <= m; i++)
			sumv += (double)vex[tem[i]];
		sume = (double)prime(f);
		ans = sume / sumv;
		if (ans < MIN)
		{
			MIN = ans;
			for (i = 1; i <= m; i++)
			{
				res[i] = tem[i];
			}
		}
		return;
	}
	if (n - f + num < m)
		return;
	for (i = f + 1; i <= n; i++)
	{
		tem[num + 1] = i;
		dfs(i, num + 1);
	}
}
