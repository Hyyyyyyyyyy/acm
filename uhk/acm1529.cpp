#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <deque>
#include <algorithm>
using namespace std;
const int MAX = 100000000;
int visit[10000], dist[10000], head[10000], ar[30], num[10000], in[10000];
struct node
{
	int to;
	int next;
	int val;
};
node edge[10000];
int cnt;
bool SPFA();
bool judge(int M);
void addedge(int x, int y, int z);
int main()
{
	int i, j, k, u, n, m, a, b, c, l, r, h, res;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			memset(head, -1, sizeof(head));
			memset(num, 0, sizeof(num));
			memset(ar, 0, sizeof(ar));
			cnt = 0;
			for (i = 1; i <= 24; i++)
			{
				scanf("%d", &ar[i]);
			}
			scanf("%d", &k);
			for (u = 1; u <= k; u++)
			{
				scanf("%d", &a);
				num[a + 1]++;
			}
			l = 0;
			r = k;
			res = -1;
			while (l <= r)
			{
				h = (l + r) / 2;
				if (judge(h))
				{
					r = h - 1;
					res = h;
				}
				else
					l = h + 1;
			}
			if (res == -1)
				printf("No Solution\n");
			else
				printf("%d\n", res);
		}
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
bool judge(int M)
{
	int i, j, t;
	memset(head, -1, sizeof(head));
	cnt = 0;
	for (i = 1; i <= 24; i++)
	{
		addedge(i, i - 1, -num[i]);
		addedge(i - 1, i, 0);
		if (i >= 8)
			addedge(i - 8, i, ar[i]);
		else
			addedge(i + 16, i, ar[i] - M);
	}
	addedge(0, 24, M);
	addedge(24, 0, -M);
	return SPFA();
}
bool SPFA()
{
	int i, j, now, after, u, v, t;
	deque<int>q;
	memset(visit, 0, sizeof(visit));
	memset(in, 0, sizeof(in));
	for (i = 0; i <= 24; i++)
		dist[i] = -MAX;
	dist[0] = 0;
	visit[0] = 1;
	in[0] = 1;
	q.push_back(0);
	while (!q.empty())
	{
		now = q.front();
		q.pop_front();
		visit[now] = 0;
		for (i = head[now]; i != -1; i = edge[i].next)
		{
			t = edge[i].to;
			v = edge[i].val;
			if (dist[t] < dist[now] + v)
			{
				dist[t] = dist[now] + v;
				if (!visit[t])
				{
					visit[t] = 1;
					if (++in[t] > 24)
						return false;
					if (!q.empty() && dist[t] > dist[q.front()])
						q.push_front(t);
					else
						q.push_back(t);
				}
			}
		}
	}
	return true;
}
