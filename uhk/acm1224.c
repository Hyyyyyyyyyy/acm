#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <deque>
#define MIN -10000000
using namespace std;
struct node
{
	int now;
	int val;
	int next;
};
struct node ar[20010];

int dist[110], head[110], pre[110], set[110], visit[110], k;
void SPFA();
void out(int q);
int main()
{
	int i, j, u, a, b, c, n, m, count;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &k);
			for (u = 1; u <= k; u++)
			{
				scanf("%d", &set[u]);
			}
			set[k + 1] = 0;
			count = 1;
			memset(head, 0 , sizeof(head));
			scanf("%d", &c);
			for (u = 1; u <= c; u++)
			{
				scanf("%d %d", &a, &b);
				ar[count].now = b;
				ar[count].val = set[b];
				ar[count].next = head[a];
				head[a] = count++;
			}
			SPFA();
			printf("CASE %d#\n", m);
			printf("points : %d\n", dist[k + 1]);
			printf("circuit : ");
			i = k + 1;
			out(pre[k+1]);
			printf("1\n");
			if (m < n)
				printf("\n");
		}
	}
	return 0;
}
void SPFA()
{
	int i, j, u, h, v;
	queue<int>q;
	memset(visit, false, sizeof(visit));
	memset(pre, 0, sizeof(pre));
	for (i = 1; i <= k + 1; i++)
		dist[i] = MIN;
	dist[1] = 0;
	visit[1] = true;
	q.push(1);
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		visit[u] = false;
		for (i = head[u]; i; i = ar[i].next)
		{
			v = ar[i].now;
			if (dist[v] < dist[u] + ar[i].val)
			{
				dist[v] = dist[u] + ar[i].val;
				pre[v] = u;
				if (!visit[v])
				{
					visit[v] = true;
					q.push(v);
				}
			}
		}
	}
}
void out(int q)
{
	if (pre[q] != 0)
		out(pre[q]);
	printf("%d->", q);
	return;
	if (pre[q])
		out(pre[q]);
	else
	{
		if (q == k+1)
			printf("circuit : 1->1");
		else
			printf("circuit : 1");

		return;
	}
	if (q == k+1)
		q = 1;
	printf("->%d", q);
}