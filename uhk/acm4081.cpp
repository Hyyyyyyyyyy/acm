#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int MIN = -10000000;
const int  MAX = 100000000;
struct Point
{
	int i;
	int x;
	int y;
	int p;
};
Point point[1010];
double ar[1010][1010], Max[1010][1010], dist[1010];
int pre[1010], visit[1010], used[1010][1010];
int cnt, N, M;
double prime()
{
	int i, j, k;
	double ans = 0.0;
	memset(visit, 0, sizeof(visit));
	memset(Max, 0, sizeof(Max));
	memset(used, 0, sizeof(used));
	visit[1] = 1;
	for (i = 1; i <= N; i++)
	{
		pre[i] = 1;
		dist[i] = ar[1][i];
	}
	pre[1] = -1;
	dist[1] = 0;
	for (i = 2; i <= N; i++)
	{
		double mindist = 1.0*MAX;
		int p = -1;
		for (j = 1; j <= N; j++)
		{
			if (!visit[j] && dist[j] < mindist)
			{
				mindist = dist[j];
				p = j;
			}
		}
		if (mindist == MAX)
			return -1.0;
		ans += mindist;
		visit[p] = 1;
		used[pre[p]][p] = used[p][pre[p]] = 1;
		for (j = 1; j <= N; j++)
		{
			if (visit[j] && j != p)
			{
				Max[j][p] = Max[p][j] = max(Max[j][pre[p]], dist[p]);
			}
			if (!visit[j] && dist[j] > ar[p][j])
			{
				dist[j] = ar[p][j];
				pre[j] = p;
			}
		}
	}
	return ans;
}
int main()
{
	int i, j, k, u, n, m, a, b, c;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &N);
			for (i = 1; i <= N; i++)
			{
				scanf("%d %d %d", &point[i].x, &point[i].y, &point[i].p);
				point[i].i = i;
			}
			for (i = 1; i <= N; i++)
			{
				for (j = i + 1; j <= N; j++)
				{
					ar[i][j] = ar[j][i] = sqrt((point[i].x - point[j].x)*(point[i].x - point[j].x) + (point[i].y - point[j].y)*(point[i].y - point[j].y));
				}
			}
			double s = prime();
			double res = 1.0*MIN;
			for (i = 1; i <= N; i++)
			{
				for (j = i + 1; j <= N; j++)
				{
					if (used[i][j])
					{
						double t = 1.0*(point[i].p + point[j].p) / (s - ar[i][j]);
						if (res < t)
							res = t;
					}
					else
					{
						double t = 1.0*(point[i].p + point[j].p) / (s - Max[i][j]);
						if (res < t)
							res = t;
					}
				}
			}
			printf("%.2f\n", res);
		}
	}
	return 0;
}