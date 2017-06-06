#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
const int maxn = 220;
const double eps = 1.0e-9;
int zushu, var;
int N, M, X, Y, D;
double a[maxn][maxn], x[maxn], p[maxn];
int visit[maxn];
void bfs()
{
	queue<int>q;
	memset(visit, 0, sizeof(visit));
	int i, j, cnt = 1, u, v;
	visit[X] = cnt++;
	q.push(X);
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		for (i = 1; i <= M; i++)
		{
			int t = (u + i) % N;
			if (fabs(p[i]) < eps)
				continue;
			if (!visit[t])
			{
				q.push(t);
				visit[t] = cnt++;
			}
		}
	}
	zushu = var = cnt - 1;
}
void build()
{
	int i, j;
	memset(a, 0, sizeof(a));
	memset(x, 0, sizeof(x));
	for (i = 0; i < N; i++)
	{
		if (visit[i])
		{
			a[visit[i]][visit[i]] = 1;
			if (i == Y || i == (N - Y))
			{
				x[visit[i]] = 0;
				continue;
			}
			for (j = 1; j <= M; j++)
			{
				if (visit[(i + j) % N])
				{
					a[visit[i]][visit[(i + j) % N]] -= p[j];
					x[visit[i]] += j*p[j];
				}
			}
		}
	}
}
int Gauss()
{
	int i, j, k, u, col, max_r;
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
		if (k != max_r)
		{
			for (j = col; j <= var; j++)
				swap(a[k][j], a[max_r][j]);
			swap(x[k], x[max_r]);
		}
		x[k] /= a[k][col];
		for (j = col + 1; j <= var; j++)
			a[k][j] /= a[k][col];
		a[k][col] = 1;
		for (i = 1; i <= zushu; i++)
		{
			if (i != k)
			{
				x[i] -= x[k] * a[i][col];
				for (j = col + 1; j <= var; j++)
					a[i][j] -= a[k][j] * a[i][col];
				a[i][col] = 0;
			}
		}
	}
	return 1;
}
int main()
{
	int i, j, k, u, b, c, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d %d %d %d", &N, &M, &Y, &X, &D);
			for (i = 1; i <= M; i++)
			{
				scanf("%lf", &p[i]);
				p[i] /= 100.0;
			}
			if (X == Y)
			{
				printf("0.00\n");
				continue;
			}
			N = (N - 1) * 2;
			if (D == 1)
				X = N - X;
			bfs();
			if (!visit[Y] && !visit[N - Y])
			{
				printf("Impossible !\n");
				continue;
			}
			build();
			if (Gauss())
			{
				printf("%.2f\n", x[visit[X]]);
			}
			else
			{
				printf("Impossible !\n");
			}
		}
	}
	return 0;
}
