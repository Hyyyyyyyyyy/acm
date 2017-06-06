#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 100000000;
int dfn[505], low[505], Instack[505], Stack[505], head[250005], belong[505], hd[250005];
int dist[505];
int Sccc, top, Index, cnt, tot;
struct node
{
	int to;
	int next;
	int val;
	node() {}
	node(int a, int b, int c) : to(a), next(b), val(c) {}
	bool operator < (const node &p) const
	{
		return val > p.val;
	}
};
node edge[250005], e[250005];
void addedge(int x, int y, int z);
void add(int x, int y, int z);
void Tarjan(int f);
void solve(int n, int m);
void dijkstra(int begin, int end);
int main()
{
	int i, j, k, n, m, u, a, b, c;
	while (scanf("%d", &n) != EOF && n)
	{
		scanf("%d", &m);
		top = Index = cnt = Sccc = tot = 0;
		memset(head, -1, sizeof(head));
		memset(hd, -1, sizeof(hd));
		memset(Instack, 0, sizeof(Instack));
		memset(dfn, 0, sizeof(dfn));
		for (i = 1; i <= m; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			addedge(a, b, c);
		}
		solve(n, m);
		putchar('\n');
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
	e[tot].to = y;
	e[tot].next = hd[x];
	e[tot].val = z;
	hd[x] = tot++;
}
void Tarjan(int f)
{
	int i, j, t;
	low[f] = dfn[f] = ++Index;
	Stack[top++] = f;
	Instack[f] = 1;
	for (i = head[f]; i != -1; i = edge[i].next)
	{
		t = edge[i].to;
		if (!dfn[t])
		{
			Tarjan(t);
			if (low[f] > low[t])
				low[f] = low[t];
		}
		else if (Instack[t] && low[f] > dfn[t])
			low[f] = dfn[t];
	}
	if (low[f] == dfn[f])
	{
		Sccc++;
		do
		{
			t = Stack[--top];
			Instack[t] = 0;
			belong[t] = Sccc;
		} while (t != f);
	}
}
void solve(int n, int m)
{
	int i, j, k, u, a, b, c;
	for (i = 1; i <= n; i++)
		if (!dfn[i])
			Tarjan(i);
	for (i = 1; i <= n; i++)
	{
		for (j = head[i]; j != -1; j = edge[j].next)
		{
			if (belong[i] != belong[edge[j].to])
			{
				add(belong[i], belong[edge[j].to], edge[j].val);
			}
		}
	}
	//for (i = 1; i <= n; i++)
	//	printf("%d ", belong[i]);
	//putchar('\n');
	scanf("%d", &k);
	for (u = 1; u <= k; u++)
	{
		scanf("%d %d", &a, &b);
		dijkstra(belong[a], belong[b]);
		if (belong[a] == belong[b])
			printf("0\n");
		else if (dist[belong[b]] != MAX)
			printf("%d\n", dist[belong[b]]);
		else
			printf("Nao e possivel entregar a carta\n");
	}
}
void dijkstra(int begin, int end)
{
	int i, j, k, u;
	priority_queue<node>q;
	for (i = 1; i <= Sccc * 2; i++)
		dist[i] = MAX;
	node temp(begin, hd[begin], 0), after;
	dist[begin] = 0;
	q.push(temp);
	while (!q.empty())
	{
		temp = q.top();
		q.pop();

		if (dist[temp.to] < temp.val)
			continue;
		for (i = hd[temp.to]; i != -1; i = e[i].next)
		{
			after.val = e[i].val;
			after.to = e[i].to;
			if (dist[after.to] > dist[temp.to] + after.val)
			{
				dist[after.to] = dist[temp.to] + after.val;
				q.push(after);
			}
		}
	}
}