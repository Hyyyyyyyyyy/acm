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
const int MAXN = 30010;
struct node
{
	int to;
	int next;
};
node edge[100010];
int head[MAXN], in[MAXN];
int cnt, N, M;
void tuobu();
void addedge(int x, int y);
int main()
{
	int i, j, k, u, n, m, a, b, c;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			memset(in, 0, sizeof(in));
			memset(head, -1, sizeof(head));
			cnt = 0;
			scanf("%d %d", &N, &M);
			for (u = 1; u <= M; u++)
			{
				scanf("%d %d", &a, &b);
				addedge(b, a);
				in[a]++;
			}
			tuobu();
			printf("\n");
		}
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
	vector<int>ar;
	ar.clear();
	int i, j, k, u, v, sta = 0;
	priority_queue<int>q;
	for (i = 1; i <= N; i++)
		if (in[i] == 0)
		{
			in[i]--;
			q.push(i);
		}
	while (!q.empty())
	{
		u= q.top();
		q.pop();
		ar.push_back(u);
		for (i = head[u]; i != -1; i = edge[i].next)
		{
			in[edge[i].to]--;
			if (in[edge[i].to] == 0)
			{
				q.push(edge[i].to);
			}
		}
	}
	for (i = ar.size() - 1; i >= 0; i--)
	{
		if (i != ar.size() - 1)
			putchar(' ');
		printf("%d", ar[i]);
	}
}