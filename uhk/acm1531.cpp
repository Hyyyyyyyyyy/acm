//spfa是判断是否成环，如果求最短路就是判断的负环（因为该环中的点在无限的更新最短距离），如果求最长路就是判断正环（因为该环中的点在无限的更新最长距离）；
//至于为什么一定要入队次数大于顶点数，因为bfs在第一次入到环时并不认识她，为了防止是所有顶点都在环中（反正遇到了正/负环会一直更新下去肯定会到顶点数的），所以必须要入队次数大于顶点数（这就是为什么bfs判环比dfs慢，dfs判断的是一个点是否在一条路径中出现超过1次，所以在第一次遇到环时就能认识她）
//1531   差分约束第6题  SPFA()判环，因为是把所有条件转化为求最短路 所以判负环（如果把所有条件转化为求最长路，就是判正环）；
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
struct node
{
	int to;
	int next;
	int val;
};
node edge[500];
int head[500], dist[500], visit[500], in[500];
int cnt, n;
void addedge(int x, int y, int z);
bool SPFA(int s);
int main()
{
	int i, j, k, m, a, b, c, u, v;
	char ch, s[5];
	while (scanf("%d", &n) != EOF && n)
	{
		scanf("%d", &m);
		cnt = 0;
		memset(head, -1, sizeof(head));
		for (i = 1; i <= m; i++)
		{
			scanf("%d %d %s %d", &u, &v, s, &k);
			if (s[0] == 'g')
			{
				addedge(u + v, u - 1, -k - 1);
			}
			else
			{
				addedge(u - 1, u + v, k - 1);
			}
		}
		int st = n + 1;
		for (i = 0; i <= n; i++)
			addedge(st, i, 0);
		if (SPFA(st))
		{
			printf("lamentable kingdom\n");
		}
		else
		{
			printf("successful conspiracy\n");
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
bool SPFA(int s)
{
	int i, j, k, u, v;
	deque<int>q;
	for (i = 0; i <= n + 1; i++)
		dist[i] = MAX;
	memset(visit, 0, sizeof(visit));
	memset(in, 0, sizeof(in));
	dist[s] = 0;
	visit[s] = 1;
	q.push_back(s);
	while (!q.empty())
	{
		u = q.front();
		q.pop_front();
		visit[u] = 0;
		for (i = head[u]; i != -1; i = edge[i].next)
		{
			v = edge[i].to;
			if (dist[v] > dist[u] + edge[i].val)
			{
				dist[v] = dist[u] + edge[i].val;
				if (!visit[v])
				{
					visit[v] = 1;
					if (++in[v] > n + 1)
						return 0;
					if (!q.empty() && dist[v] < dist[q.front()])
						q.push_front(v);
					else
						q.push_back(v);
				}
			}
		}
	}
	return 1;
}