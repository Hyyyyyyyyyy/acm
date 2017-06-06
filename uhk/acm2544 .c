#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 100000000
int n, m;
int ar[110][110], dist[110];
bool visit[110];
void dijkstra();
int main()
{
	int i, j, k, u, a, b, c;

	while (scanf("%d %d", &n, &m) != EOF && (n || m))
	{
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				ar[i][j] = MAX;
			}
		}
		memset(visit, false, sizeof(visit));
		for (u = 1; u <= m; u++)
		{
			scanf("%d %d %d", &a, &b, &c);
			ar[a][b] = c;
			ar[b][a] = c;
		}
		dijkstra();
		printf("%d\n", dist[n]);
	}
	return 0;
}
void dijkstra()
{
	int i, j, k, u, midmin, near;
	for (i = 1; i <= n; i++)
		dist[i] = ar[1][i];
	dist[1] = 0;
	visit[1] = true;
	for (i = 2; i <= n; i++)
	{
		midmin = MAX;
		near = MAX;
		for (j = 2; j <= n; j++)
		{
			if (!visit[j] && dist[j] < midmin)
			{
				midmin = dist[j];
				near = j;
			}
		}
		visit[near] = true;
		for (j = 2; j <= n; j++)
		{
			if (!visit[j] && ar[near][j] != MAX && dist[near] + ar[near][j] < dist[j])						
			{
				dist[j] = dist[near] + ar[near][j];																									
			}
		}
	}
}
