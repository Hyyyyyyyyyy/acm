#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int id(int a, int b, int c) { return (a - 1)*c + b; }
const int maxn = 110;
int dir[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
struct Node
{
	int x;
	int y;
	Node()
	{
		x = -1;
		y = -1;
	}
	Node(int a, int b) : x(a), y(b) {}
	Node(const Node& p)
	{
		x = p.x;
		y = p.y;
	}
	void operator = (const Node& p)
	{
		x = p.x;
		y = p.y;
	}
};
Node node;
int ar[maxn][maxn];
int visit[maxn][maxn];
Node link[maxn][maxn];
int N, M;
bool dfs(Node f)
{
	int i, j, k, n, m;
	for (i = 0; i < 4; i++)
	{
		Node temp(f.x + dir[i][0], f.y + dir[i][1]);
		if (temp.x > N || temp.x < 1 || temp.y > M || temp.y < 1 || visit[temp.x][temp.y] || ar[temp.x][temp.y])
			continue;
		visit[temp.x][temp.y] = 1;
		if (link[temp.x][temp.y].x == -1 || dfs(link[temp.x][temp.y]))
		{
			link[temp.x][temp.y] = f;
			return true;
		}
	}
	return false;
}
int main()
{
	int i, j, k, u, n, m, a, b;
	while (scanf("%d %d", &N, &M) != EOF && N + M)
	{
		scanf("%d", &n);
		memset(ar, 0, sizeof(ar));
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= M; j++)
				link[i][j].x = link[i][j].y = -1;
		}
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &a, &b);
			ar[a][b] = 1;
		}
		int res = 0;
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= M; j++)
			{
				if ((i + j) % 2 && ar[i][j] == 0)
				{
					memset(visit, 0, sizeof(visit));
					if (dfs(Node(i, j)))
						res++;
				}
			}
		}
		printf("%d\n", res);
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= M; j++)
			{
				if (link[i][j].x != -1 && (i + j) % 2 == 0)
				{
					printf("(%d,%d)--(%d,%d)\n", i, j, link[i][j].x, link[i][j].y);
				}
			}
		}
		putchar('\n');
	}
	return 0;
}