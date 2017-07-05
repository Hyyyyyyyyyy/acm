#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 10000 + 100;
typedef long long ll;
int set[maxn];
int visit[maxn], pre[maxn];
int ans[maxn], res[maxn];
int N, n;
int bfs()
{
	int i, j;
	memset(visit, 0, sizeof(visit));
	queue<int>q;
	q.push(0);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (i = 0; i <= 9; i++)
		{
			int v = (u * 10 + i) % N;
			if (set[i] || visit[v] || u ==0 && i == 0)
				continue;
			visit[v] = 1;
			ans[v] = i;
			pre[v] = u;
			q.push(v);
			if (v == 0)
				return v;
		}
	}
	return -1;
}
void print(int u)
{
	if (pre[u] != 0)
		print(pre[u]);
	printf("%d", ans[u]);
}
int main()
{
	int i, j, k, u, m, a, b, cas =  1;
	while (scanf("%d", &N) != EOF)
	{
		scanf("%d", &n);
		memset(set, 0, sizeof(set));
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &a);
			set[a] = 1;
		}
		int v = bfs();
		printf("Case %d: ", cas++);
		if (v != -1)
		{
			print(v);
			putchar('\n');
		}
		else
			printf("-1\n");
	}
	return 0;
}