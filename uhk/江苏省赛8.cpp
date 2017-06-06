#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 100000000;
struct node
{
	int to;
	int next;
	int val;
	bool operator < (const node& p) const
	{
		return val > p.val;
	}
};
node edge[200000];
map<string, int>q;
int head[200000], dist[200000];
int cnt, N, M, Count;
void addedge(int x, int y, int z);
void dijkstra(int begin);
int main()
{
	int i, j, k, u, n, m, a, b, c;
	char s[50], ss[50][50], begin[50], end[50];
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			q.clear();
			memset(head, -1, sizeof(head));
			Count = cnt = 0;
			scanf("%d", &N);
			for (i = 1; i <= N; i++)
			{
				scanf("%s", s);
				if (strcmp(s, "B") == 0)
				{
					scanf("%d", &k);
					for (j = 1; j <= k; j++)
					{
						scanf("%s", ss[j]);
						if (q[ss[j]] == 0)
						{
							q[ss[j]] = Count++;
						}
					}
					for (j = 1; j <= k; j++)
					{
						for (u = j + 1; u <= k; u++)
						{
							addedge(q[ss[j]], q[ss[u]], 0);
							addedge(q[ss[u]], q[ss[j]], 0);
						}
					}
				}
				else
				{
					scanf("%d", &k);
					for (j = 1; j <= k; j++)
					{
						scanf("%s", ss[j]);
						if (q[ss[j]] == 0)
						{
							q[ss[j]] = Count++;
						}
					}
					for (j = 1; j <= k; j++)
					{
						for (u = j + 1; u <= k; u++)
						{
							addedge(q[ss[j]], q[ss[u]], 2);
							addedge(q[ss[u]], q[ss[j]], 2);
						}
					}
				}
			}
			scanf("%s %s", begin, end);
			dijkstra(q[begin]);
			printf("Case #%d: %d\n", m, dist[q[end]]);
		}
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
void dijkstra(int begin)
{
	priority_queue<node>p;
	int i, j, k;
	node now, after;
	for (i = 0; i <= Count; i++)
	{
		dist[i] = MAX;
	}
	now.to = begin;
	now.val = 0;
	now.next = head[begin];
	dist[begin] = 0;
	p.push(now);
	while (!p.empty())
	{
		now = p.top();
		p.pop();
		for (i = head[now.to]; i != -1; i = edge[i].next)
		{
			after = edge[i];
			if (dist[after.to] > dist[now.to] + after.val)
			{
				dist[after.to] = dist[now.to] + after.val;
				p.push(after);
			}
		}
	}
}
