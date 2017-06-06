#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int dfn[5010], low[5010];
int Instack[5010], Stack[5010];
int num[5010], belong[5010], head[5010], hd[5010];
int visit[5010];
int link[5010];
struct node
{
	int from;
	int to;
	int next;
};
node edge[100010], e[100010];
int Sccc, top, cnt, tot, Index;
void addedge(int x, int y);
void add(int x, int y);
void Tarjan(int f);
void solve(int n, int m);
bool dfs(int f);
int main()
{
	int i, j, k, u, N, M, n, m, a, b;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			Sccc = top = cnt = tot = Index = 0;
			memset(head, -1, sizeof(head));
			memset(hd, -1, sizeof(hd));
			memset(Instack, 0, sizeof(Instack));
			memset(dfn, 0, sizeof(dfn));
			memset(belong, -1, sizeof(belong));
			memset(num, 0, sizeof(num));
			memset(visit, 0, sizeof(visit));
			memset(link, -1, sizeof(link));
			scanf("%d %d", &N, &M);
			for (i = 1; i <= M; i++)
			{
				scanf("%d %d", &a, &b);
				addedge(a, b);
			}
			solve(N, M);
		}
	}
	return 0;
}
void addedge(int x, int y)
{
	edge[cnt].from = x;
	edge[cnt].to = y;
	edge[cnt].next = head[x];
	head[x] = cnt++;
}
void add(int x, int y)
{
	e[tot].from = x;
	e[tot].to = y;
	e[tot].next = hd[x];
	hd[x] = tot++;
}
void Tarjan(int f)
{
	int i, j, k, temp;
	dfn[f] = low[f] = ++Index;
	Stack[top++] = f;
	Instack[f] = 1;
	for (i = head[f]; i != -1; i = edge[i].next)
	{
		temp = edge[i].to;
		if (!dfn[temp])
		{
			Tarjan(temp);
			if (low[f] > low[temp])
				low[f] = low[temp];
		}
		else if (Instack[temp] && low[f] > dfn[temp])
			low[f] = dfn[temp];
	}
	if (low[f] == dfn[f])
	{
		Sccc++;
		do
		{
			temp = Stack[--top];
			Instack[temp] = 0;
			num[Sccc]++;
			belong[temp] = Sccc;
		} while (temp != f);
	}
}
void solve(int n, int m)
{
	int i, j, k, sum = 0;
	for (i = 1; i <= n; i++)
	{
		if (!dfn[i])
			Tarjan(i);
	}
	for (i = 1; i <= n; i++)
	{
		for (j = head[i]; j != -1; j = edge[j].next)
		{
			if (belong[i] != belong[edge[j].to])
			{
				add(belong[i], belong[edge[j].to]);
			}
		}
	}
	for (i = 1; i <= Sccc; i++)
	{
		memset(visit, 0, sizeof(visit));
		if (!visit[i])
			if (dfs(i))
				sum++;
	}
	printf("%d\n", Sccc - sum);
}
bool dfs(int f)
{
	int i, j, k;
	visit[f] = 1;
	for (i = hd[f]; i != -1; i = e[i].next)
	{
		if (!visit[e[i].to])
		{
			visit[e[i].to] = 1;
			if (link[e[i].to] == -1 || dfs(link[e[i].to]))
			{
				link[e[i].to] = f;
				return true;
			}
		}
	}
	return false;
}
