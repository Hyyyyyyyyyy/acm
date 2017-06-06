#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MAX = 100000000;
int Stack[1010], Instack[1010];
int dfn[1010], low[1010];
int head[1010];
int val[1010];
int num[1010], set[1010];
int Sccc, top, cnt, Index;
struct node
{
	int from;
	int to;
	int next;
};
node edge[2010];
void add(int a, int b);
void Tarjan(int f);
int solve(int n);
int main()
{
	int i, j, k, x, y, n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		for (i = 1; i <= n; i++)
			scanf("%d", &val[i]);
		Index = Sccc = top = cnt = 0;
		memset(head, -1, sizeof(head));
		memset(Instack, 0, sizeof(Instack));
		memset(dfn, 0, sizeof(dfn));
		memset(set, 0, sizeof(set));
		memset(num, -1, sizeof(num));
		for (i = 1; i <= m; i++)
		{
			scanf("%d %d", &x, &y);
			add(x, y);
		}
		j = solve(n);
		printf("%d %d\n", Sccc, j);
	}
}
void add(int a, int b)
{
	edge[cnt].from = a;
	edge[cnt].to = b;
	edge[cnt].next = head[a];
	head[a] = cnt++;
}
int solve(int n)
{
	int i, j, sum = 0, min;
	for (i = 1; i <= n; i++)
	{
		if (!dfn[i])
			Tarjan(i);
	}
	for (i = 0; i < cnt; i++)
	{
		if (num[edge[i].from] == num[edge[i].to])
			continue;
		set[num[edge[i].to]]++;
	}
	for (i = 1; i <= n; i++)
	{
		if (num[i] != i)
			continue;
		if (set[i])
			continue;
		Sccc++;
		min = MAX;
		for (j = 1; j <= n; j++)
		{
			if (num[j] == i && val[j] < min)
				min = val[j];
		}
		sum += min;
	}
	return sum;
}
void Tarjan(int f)
{
	int i, k, j, temp;
	low[f] = dfn[f] = ++Index;
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
		do
		{
			temp = Stack[--top];
			Instack[temp] = 0;
			num[temp] = f;
		} while (temp != f);
	}
}