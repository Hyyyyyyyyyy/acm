#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <set>
using namespace std;
const int MAX = 100000 + 10;
const int INF = 1e10;
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
bool comp(int a, int b)
{
	return a < b;
}
node edge[100000 * 2];
int head[100000 * 2], dist[100000*2];
int B[MAX], E[MAX];
int cnt, N, M, K1, K2;
void addedge(int x, int y, int z);
void dijkstra(int begin);
int main()
{
	int i, j, k, u, n, m, a, b, c;
	while (scanf("%d %d", &N, &M) != EOF)
	{
		cnt = 0;
		memset(head, -1, sizeof(head));
		for (m = 1; m <= M; m++)
		{
			scanf("%d %d %d", &a, &b, &c);
			addedge(a, b, c);
		}
		scanf("%d", &K1);
		for (i = 1; i <= K1; i++)
		{
			scanf("%d", &B[i]);
		}
		scanf("%d", &K2);
		for (i = 1; i <= K2; i++)
		{
			scanf("%d", &E[i]);
		}
		//set<int>::iterator q, r;
		int MIN = INF;
		for (i = 1; i <= K1; i++)
		{
			addedge(0, B[i], 0);
		}
		dijkstra(0);
		for (i = 1; i <= K2; i++)
		{
			if (MIN > dist[E[i]])
				MIN = dist[E[i]];
		}
		printf("%d\n", MIN);
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
	for (i = 0; i <= N; i++)
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