#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <deque>
using namespace std;
const int MAX = 100000000;
const int MIN = -100000000;
int visit[50010], head[100010], dist[50010];
struct node
{
	int val;
	int next;
	int to;
};
node edge[400010];
int Max, Min, cnt, top;
void addedge(int x, int y, int z);
int SPFA();
int main()
{
	int i, j, k, u, n, m, a, b, c;
	while (scanf("%d", &n) != EOF)
	{
		Max = MIN;
		Min = MAX;
		memset(head, -1, sizeof(head));
		cnt = 0;
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d %d", &a, &b, &c);
			if (Max < b)
				Max = b;
			if (Min > a)
				Min = a;
			addedge(a - 1, b, c);
		}
		for (m = Min; m <= Max; m++)
		{
			addedge(m - 1, m, 0);
			addedge(m, m - 1, -1);
		}
		printf("%d\n", SPFA());
	}
	return 0;
}
void addedge(int x, int y, int z)
{
	edge[cnt].to = y;
	edge[cnt].val = z;
	edge[cnt].next = head[x];
	head[x] = cnt++;
}
int SPFA()
{
	int i, j, u, t, v;
	deque<int>q;
	memset(visit, 0, sizeof(visit));
	memset(dist, -1, sizeof(dist));
	dist[Min - 1] = 0;
	q.push_back(Min - 1);
	visit[Min - 1] = 1;
	while (!q.empty())
	{
		t = q.front();
		q.pop_front();
		visit[t] = 0;
		for (i = head[t]; i != -1; i = edge[i].next)
		{
			u = edge[i].to;
			v = edge[i].val;
			if (dist[u] < dist[t] + v)
			{
				dist[u] = dist[t] + v;
				if (!visit[u])
				{
					visit[u]++;
					if (!q.empty() && dist[u] > dist[q.front()])
						q.push_front(u);
					else
						q.push_back(u);
				}
			}
		}
	}
	return dist[Max];
}