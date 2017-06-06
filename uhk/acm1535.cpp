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
typedef long long ll;
const int MAX = 100000000;
const int MAXN = 1000010;
struct node
{
	int to;
	int next;
	int val;
};
node edge[4 * MAXN], e[4 * MAXN];
int visit[MAXN], dist[MAXN], head[MAXN], hd[MAXN], in[MAXN];
int cnt, Count, P, Q;
void addedge(int x, int y, int z);
void add(int x, int y, int z);
void SPFA1();
void SPFA2();
int main()
{
	int i, j, k, n, m, u, a, b, c;
	ll sum;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			memset(head, -1, sizeof(head));
			memset(hd, -1, sizeof(hd));
			cnt = Count = 0;
			scanf("%d %d", &P, &Q);
			for (u = 1; u <= Q; u++)
			{
				scanf("%d %d %d", &a, &b, &c);
				addedge(a, b, c);
				add(b, a, c);
			}
			SPFA1();
			sum = 0;
			for (i = 1; i <= P; i++)
			{
				sum += dist[i];
			}
			SPFA2();
			for (i = 1; i <= P; i++)
			{
				sum += dist[i];
			}
			printf("%lld\n", sum);
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
void add(int x, int y, int z)
{
	e[Count].to = y;
	e[Count].val = z;
	e[Count].next = hd[x];
	hd[x] = Count++;
}
void SPFA1()
{
	int i, j, k, u, v, t;
	deque<int>q;
	memset(visit, 0, sizeof(visit));
	memset(in, 0, sizeof(in));
	for (i = 1; i <= P; i++)
		dist[i] = MAX;
	dist[1] = 0;
	visit[1] = 1;
	q.push_back(1);
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
					if (++in[v] > P)
						return;
					if (!q.empty() && dist[v] < dist[q.front()])
						q.push_front(v);
					else
						q.push_back(v);
				}
			}
		}
	}
}
void SPFA2()
{
	int i, j, k, u, v, t;
	deque<int>q;
	memset(visit, 0, sizeof(visit));
	memset(in, 0, sizeof(in));
	for (i = 1; i <= P; i++)
		dist[i] = MAX;
	dist[1] = 0;
	visit[1] = 1;
	q.push_back(1);
	while (!q.empty())
	{
		u = q.front();
		q.pop_front();
		visit[u] = 0;
		for (i = hd[u]; i != -1; i = e[i].next)
		{
			v = e[i].to;
			if (dist[v] > dist[u] + e[i].val)
			{
				dist[v] = dist[u] + e[i].val;
				if (!visit[v])
				{
					visit[v] = 1;
					if (++in[v] > P)
						return;
					if (!q.empty() && dist[v] < dist[q.front()])
						q.push_front(v);
					else
						q.push_back(v);
				}
			}
		}
	}
}