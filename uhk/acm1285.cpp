#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 100000000;
const int MAXN = 510;
struct node
{
	int to;
	int next;
	bool operator < (const node &p) const
	{
		return to > p.to;
	}
};
node edge[MAXN * 10];
int head[MAXN], in[MAXN];
int cnt, N;
void addedge(int x, int y);
void tuobu();
int main()
{
	int i, j, k, u, n, m, a, b;
	while (scanf("%d %d", &N, &m) != EOF)
	{
		memset(head, -1, sizeof(head));
		memset(in, 0, sizeof(in));
		cnt = 0;
		for (u = 1; u <= m; u++)
		{
			scanf("%d %d", &a, &b);
			addedge(a, b);
			in[b]++;
		}
		tuobu();
		putchar('\n');
	}
	return 0;
}
void addedge(int x, int y)
{
	edge[cnt].to = y;
	edge[cnt].next = head[x];
	head[x] = cnt++;
}
void tuobu()
{
	int i, j, k, u, v, t, doudou = 0;
	node now, after;
	priority_queue<node>q;
	for (i = 1; i <= N; i++)
	{
		if (in[i] == 0)
		{
			now.to = i;
			now.next = head[i];
			q.push(now);
			in[i]--;
		}
	}
	while (!q.empty())
	{
		now = q.top();
		q.pop();
		if (doudou)
			putchar(' ');
		doudou = 1;
		printf("%d", now.to);
		for (i = head[now.to]; i != -1; i = edge[i].next)
		{
			after = edge[i];
			in[after.to]--;
			if (in[after.to] == 0)
			{
				q.push(after);
			}
		}
	}
}