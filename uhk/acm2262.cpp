#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 20;
const double eps = 1.0e-9;
struct Node
{
	int x;
	int y;
};
Node now, after;
int N, M, bx, by, zushu, var, Count;
int dir[4][2] = { -1, 0, 0, -1, 1, 0, 0, 1 };
char ar[maxn][maxn];
int visit[maxn][maxn];
double a[maxn*maxn][maxn*maxn], x[maxn*maxn];
vector<int>G[maxn*maxn];
int bfs()
{
	int i, j, doudou = 0;
	Count = 1;
	queue<Node>q;
	memset(visit, 0, sizeof(visit));
	now.x = bx;
	now.y = by;
	q.push(now);
	visit[now.x][now.y] = Count++;
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		for (i = 0; i < 4; i++)
		{
			after.x = now.x + dir[i][0];
			after.y = now.y + dir[i][1];
			if (after.x < 1 || after.y < 1 || after.x > N || after.y > M || ar[after.x][after.y] == '#')
				continue;
			if (ar[after.x][after.y] == '$')
				doudou = 1;
			if (!visit[after.x][after.y])
			{
				q.push(after);
				visit[after.x][after.y] = Count++;
			}
		}
	}
	return doudou;
}
void build()
{
	int i, j, k, u;
	for (i = 0; i < maxn*maxn; i++)
		G[i].clear();
	memset(a, 0, sizeof(a));
	memset(x, 0, sizeof(x));
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			if (visit[i][j])
			{
				if (ar[i][j] == '$')
				{
					a[visit[i][j]][visit[i][j]] = 1;
					x[visit[i][j]] = 0;
					continue;
				}
				int cnt = 0;
				for (u = 0; u < 4; u++)
				{
					int xx = i + dir[u][0];
					int yy = j + dir[u][1];
					if (xx < 1 || xx > N || yy < 1 || yy > M || ar[xx][yy] == '#')
						continue;
					if (!visit[xx][yy])
						continue;
					cnt++;
					G[visit[i][j]].push_back(visit[xx][yy]);
				}
				a[visit[i][j]][visit[i][j]] = cnt;
				for (u = 0; u < G[visit[i][j]].size(); u++)
				{
					a[visit[i][j]][G[visit[i][j]][u]] = -1;
				}
				x[visit[i][j]] = cnt;
			}
		}
	}
}
int Guass()
{
	int i, j, k, u, max_r, col;
	for (k = 1, col = 1; k <= zushu && col <= var; k++, col++)
	{
		max_r = k;
		for (i = k + 1; i <= zushu; i++)
		{
			if (fabs(a[i][col]) > fabs(a[max_r][col]))
				max_r = i;
		}
		if (fabs(a[max_r][col]) < eps)
			return 0;
		if (max_r != k)
		{
			for (i = col; i <= var; i++)
			{
				swap(a[k][i], a[max_r][i]);
			}
			swap(x[k], x[max_r]);
		}
		for (j = col + 1; j <= var; j++)
		{
			a[k][j] /= a[k][col];
		}
		x[k] /= a[k][col];
		a[k][col] = 1;
		for (i = 1; i <= zushu; i++)
		{
			if (i != k)
			{
				for (j = col + 1; j <= var; j++)
				{
					a[i][j] -= a[k][j] * a[i][col];
				}
				x[i] -= x[k] * a[i][col];
				a[i][col] = 0;
			}
		}
	}
	return 1;
}
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d %d", &N, &M) != EOF)
	{
		for (i = 1; i <= N; i++)
		{
			scanf("%s", ar[i] + 1);
			for (j = 1; j <= M; j++)
			{
				if (ar[i][j] == '@')
				{
					bx = i;
					by = j;
				}
			}
		}
		if (!bfs())
		{
			printf("-1\n");
			continue;
		}
		zushu = var = Count - 1;
		build();
		if (Guass())
		{
			printf("%.6f\n", x[visit[bx][by]]);
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}