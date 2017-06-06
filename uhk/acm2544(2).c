#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#define MAX 100000000
using namespace std;

int num[110], ar[110][110], dist[110], n, m;
bool visit[110];
void SPFA();

int main()
{
	int i, j, k, u, a, b, c;
	while (scanf("%d %d", &n, &m) != EOF && (n || m))
	{
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				ar[i][j] = (i == j) ? 0 : MAX;
			}
		}
		for (u = 1; u <= m; u++)
		{
			scanf("%d %d %d", &a, &b, &c);
			ar[a][b] = c;
			ar[b][a] = c;
		}
		SPFA();
		printf("%d\n", dist[n]);
	}
	return 0;
}
void SPFA()
{
	int i, j, k, u, near;
	queue<int>q;
	memset(num, 0, sizeof(num));
	memset(visit, false, sizeof(visit));
	for (i = 0; i <= n; i++)
		dist[i] = MAX;
	dist[1] = 0;
	q.push(1);
	while (!q.empty())
	{
		near = q.front();
		q.pop();
		visit[near] = false;
		for (i = 1; i <= n; i++)
		{
			if (dist[i] > dist[near] + ar[near][i])
			{
				dist[i] = dist[near] + ar[near][i];
				if (!visit[i])
				{
					visit[i] = true;
					num[i]++;
					if (num[i] >= n)
						return;
					q.push(i);
				}
			}
		}
	}
}