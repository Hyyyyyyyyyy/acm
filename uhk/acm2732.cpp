#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
const int INF = 2147483640;
const int maxn = 2200;
const int maxm = 600000;
struct ISAP
{
	struct Edge
	{
		int to;
		int next;
		int cap;
		int flow;
	};
	Edge edge[maxm];
	int tol;
	int head[maxn];
	int gap[maxn];
	int dep[maxn];
	int cur[maxn];
	int S[maxn];
	int start;
	int end;
	int N;
	void init()
	{
		tol = 0;
		memset(head, -1, sizeof(head));
	}
	void addedge(int u, int v, int w, int rw = 0)
	{
		edge[tol].to = v;
		edge[tol].cap = w;
		edge[tol].flow = 0;
		edge[tol].next = head[u];
		head[u] = tol++;
		edge[tol].to = u;
		edge[tol].cap = rw;
		edge[tol].flow = 0;
		edge[tol].next = head[v];
		head[v] = tol++;
	}
	void bfs()
	{
		int i, j;
		queue<int>q;
		memset(dep, -1, sizeof(dep));
		memset(gap, 0, sizeof(gap));
		gap[0] = 1;
		dep[end] = 0;
		q.push(end);
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (i = head[u]; i != -1; i = edge[i].next)
			{
				int v = edge[i].to;
				if (dep[v] != -1)
					continue;
				dep[v] = dep[u] + 1;
				gap[dep[v]]++;
				q.push(v);
			}
		}
	}
	int max_flow()
	{
		int i, j;
		bfs();
		memcpy(cur, head, sizeof(head));
		int top = 0;
		int u = start;
		int ans = 0;
		while (dep[start] < N)
		{
			if (u == end)
			{
				int Min = INF;
				int inser;
				for (i = 0; i < top; i++)
				{
					if (Min > edge[S[i]].cap - edge[S[i]].flow)
					{
						Min = edge[S[i]].cap - edge[S[i]].flow;
						inser = i;
					}
				}
				for (i = 0; i < top; i++)
				{
					edge[S[i]].flow += Min;
					edge[S[i] ^ 1].flow -= Min;
				}
				ans += Min;
				top = inser;
				u = edge[S[top] ^ 1].to;
				continue;
			}
			bool flag = false;
			int v;
			for (i = cur[u]; i != -1; i = edge[i].next)
			{
				v = edge[i].to;
				if (edge[i].cap - edge[i].flow && dep[v] == dep[u] - 1)
				{
					flag = true;
					cur[u] = i;
					break;
				}
			}
			if (flag)
			{
				S[top++] = cur[u];
				u = v;
				continue;
			}
			int Min = N;
			for (i = head[u]; i != -1; i = edge[i].next)
			{
				if (edge[i].cap - edge[i].flow && dep[edge[i].to] < Min)
				{
					Min = dep[edge[i].to];
					cur[u] = i;
				}
			}
			gap[dep[u]]--;
			if (!gap[dep[u]])
				return ans;
			dep[u] = Min + 1;
			gap[dep[u]]++;
			if (u != start)
				u = edge[S[--top] ^ 1].to;
		}
		return ans;
	}
};
ISAP isap;

int N, M, D;
int mat[30][30];
char ar[30][30];
char sa[30][30];
int dir[4][2] = { 0 , 1, 1, 0, 0, -1, -1, 0};
int visit[30][30];
void dfs(int x, int y, int dep, int bx, int by)
{
	if (dep > D)
		return;
	int i, j;
	for (i = 0; i < 4; i++)
	{
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if (xx < 1 || xx > N || yy < 1 || yy > M || visit[xx][yy])
			continue;
		if (mat[xx][yy])
			isap.addedge(mat[bx][by] * 2, mat[xx][yy] * 2 - 1, INF);
		visit[xx][yy] = 1;
		dfs(xx, yy, dep + 1, bx, by);
	}
}
int main()
{
	int i, j, k, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &N, &D);
			for (i = 1; i <= N; i++)
			{
				scanf("%s", ar[i] + 1);
			}
			for (i = 1; i <= N; i++)
			{
				scanf("%s", sa[i] + 1);
			}
			memset(mat, 0, sizeof(mat));
			isap.init();
			M = strlen(ar[1] + 1);
			int tot = 0;
			for (i = 1; i <= N; i++)
			{
				for (j = 1; j <= M; j++)
				{
					if (ar[i][j] > '0')
					{
						mat[i][j] = ++tot;
						isap.addedge(tot * 2 - 1, tot * 2, ar[i][j] - '0');
					}
				}
			}
			int sum = 0;
			for (i = 1; i <= N; i++)
			{
				for (j = 1; j <= M; j++)
				{
					if (sa[i][j] == 'L')
					{
						isap.addedge(0, mat[i][j] * 2 - 1, 1);
						sum++;
					}
				}
			}
			int start = 0;
			int end = 1 + tot * 2;
			isap.N = 2 + tot * 2;
			isap.start = 0;
			isap.end = end;
			for (i = 1; i <= N; i++)
			{
				for (j = 1; j <= M; j++)
				{
					if (mat[i][j])
					{
						//for (int x = -D; x <= D; x++)
						//	for (int y = abs(x) - D; y <= D - abs(x); y++)
						//	{
						//		int newi = i + x;
						//		int newj = j + y;
						//		if (newi<=0 || newi > N || newj<=0 || newj > M)continue;
						//		if (mat[newi][newj] == 0)continue;
						//		if (newi == i&&newj == j)continue;
						//		isap.addedge(2 * mat[i][j], 2 * mat[newi][newj] - 1, INF);
						//	}
						memset(visit, 0, sizeof(visit));
						visit[i][j] = 1;
						dfs(i, j, 1, i, j);
						if (i <= D || j <= D || i > N - D || j > M - D)
							isap.addedge(mat[i][j] * 2, end, INF);
					}
				}
			}
			int res = sum - isap.max_flow();
			if (res == 0)
			{
				printf("Case #%d: no lizard was left behind.\n", m);
			}
			else if (res == 1)
			{
				printf("Case #%d: 1 lizard was left behind.\n", m);
			}
			else
			{
				printf("Case #%d: %d lizards were left behind.\n", m, res);
			}
		}
	}
	return 0;
}
