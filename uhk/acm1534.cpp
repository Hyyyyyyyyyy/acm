#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <queue>
#include <deque>
#include <vector>
#include <map>
using namespace std;
const int MAX = 100000000;
const int MAXN = 100010;
bool SPFA();
void addedge(int x, int y, int z);
int ar[MAXN], head[MAXN], visit[MAXN], in[MAXN], dist[MAXN];
struct node
{
	int to;
	int next;
	int val;
};
node edge[MAXN * 4];
int cnt, n;
int main()
{
	int i, j, k, u, m, a, b, c, cas = 1;
	char s[5];
	while (scanf("%d", &n) != EOF && n)
	{
		cnt = 0;
		memset(head, -1, sizeof(head));
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &ar[m]);
		}
		while (scanf("%s", s) != NULL && strcmp(s, "#"))
		{
			scanf("%d %d", &a, &b);
			if (s[0] == 'S' && s[2] == 'S')
				addedge(b, a, 0);
			if (s[0] == 'S' && s[2] == 'F')
				addedge(b, a, ar[b]);
			if (s[0] == 'F' && s[2] == 'S')
				addedge(b, a, -ar[a]);
			if (s[0] == 'F' && s[2] == 'F')
				addedge(b, a, ar[b] - ar[a]);
		}
		for (i = 1; i <= n; i++)
			addedge(0, i, 0);
		printf("Case %d:\n", cas++);
		if (SPFA())
		{
			for (i = 1; i <= n; i++)
				printf("%d %d\n", i, dist[i]);
		}
		else
			printf("impossible\n");
		printf("\n");
	}
	return 0;
}
void addedge(int x, int y, int z)
{
	edge[cnt].to = y;
	edge[cnt].next = head[x];
	edge[cnt].val = z;
	head[x] = cnt++;
}
bool SPFA()
{
	int i, j, k, u, v, t;
	deque<int>q;
	memset(visit, 0, sizeof(visit));
	memset(in, 0, sizeof(in));
	for (i = 1; i <= n; i++)
		dist[i] = -MAX;
	dist[0] = 0;
	visit[0] = 1;
	q.push_back(0);
	while (!q.empty())
	{
		u = q.front();
		q.pop_front();
		visit[u] = 0;
		for (i = head[u]; i != -1; i = edge[i].next)
		{
			v = edge[i].to;
			if (dist[v] < dist[u] + edge[i].val)
			{
				dist[v] = dist[u] + edge[i].val;
				if (!visit[v])
				{
					visit[v] = 1;
					if (++in[v] > n + 1)
						return false;
					if (!q.empty() && dist[v] > dist[q.front()])
						q.push_front(v);
					else
						q.push_back(v);
				}
			}
		}
	}
	return true;
}