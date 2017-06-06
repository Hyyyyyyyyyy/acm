#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1000000000;
struct node
{
	int to;
	int from;
	int next;
};
node edge[50010];
int dfn[10010], low[10010];
int Instack[10010], Stack[10010];
int head[10010];
int num[10010], belong[10010];
int out[10010];
int top, Index, Sccc, cnt;
void addedge(int x, int y);
void solve(int n, int m);
void Tarjan(int f);
int main()
{
	int i, j, k, n, m, a, b, p, q;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		top = Index = cnt = Sccc = 0;
		memset(head, -1, sizeof(head));
		memset(Instack, 0, sizeof(Instack));
		memset(dfn, 0, sizeof(dfn));
		memset(num, 0, sizeof(num));
		memset(out, 0, sizeof(out));
		for (i = 1; i <= m; i++)
		{
			scanf("%d %d", &a, &b);
			addedge(a, b);
		}
		solve(n, m);
	}
	return 0;
}
void addedge(int x, int y)
{
	edge[cnt].to = y;
	edge[cnt].from = x;
	edge[cnt].next = head[x];
	head[x] = cnt++;
}
void Tarjan(int f)
{
	int i, j, t;
	Stack[top++] = f;
	Instack[f] = 1;
	low[f] = dfn[f] = ++Index;
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
			num[Sccc]++;
			belong[t] = Sccc;
		} while (t != f);
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
				out[belong[i]]++;
			}
		}
	}
	if (Sccc == 1)
	{
		printf("%d\n", n);
		return;
	}
	for (i = 1; i <= Sccc; i++)
	{
		if (!out[i])
			sum++;
	}
	if (sum == 1)
	{
		for (i = 1; i <= Sccc; i++)
		{
			if (!out[i])
			{
				printf("%d\n", num[i]);
				return;
			}
		}
	}
	else
		printf("0\n");
}