#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
const int MAXn = 100 + 100;
const int INF = 1000000000;
int ar[MAXn][MAXn], sa[MAXn][MAXn];
int N, M;
int MIN[MAXn], MAX[MAXn];
int main()
{
	int i, j, k, u, n, m, a, b, doudou;
	while (scanf("%d %d", &N, &M) != EOF)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= M; j++)
			{
				scanf("%d", &ar[i][j]);
				MAX[j] = INF;
			}
			MIN[i] = INF;
		}
		memset(sa, 0, sizeof(sa));
		doudou = 1;
		if (N <= M)
		{
			for (i = 1; i <= N; i++)
			{
				for (j = 1; j <= M; j++)
				{
					if (ar[i][j] < MIN[i])
						MIN[i] = ar[i][j];
				}
				for (j = 1; j <= M; j++)
				{
					sa[i][j] = MIN[i];
				}
			}
			for (j = 1; j <= M; j++)
			{
				for (i = 1; i <= N; i++)
				{
					if (ar[i][j] - sa[i][j] < MAX[j])
						MAX[j] = ar[i][j] - sa[i][j];
				}
				for (i = 1; i <= N; i++)
				{
					sa[i][j] += MAX[j];
					if (sa[i][j] != ar[i][j])
					{
						printf("-1\n");
						return 0;
					}
				}
			}
			int cnt = 0;
			for (i = 1; i <= N; i++)
			{
				if (MIN[i] > 0)
					cnt += MIN[i];
			}
			for (j = 1; j <= M; j++)
			{
				if (MAX[j] > 0)
					cnt += MAX[j];
			}
			printf("%d\n", cnt);
			for (i = 1; i <= N; i++)
			{
				if (MIN[i] > 0)
				{
					for (k = 1; k <= MIN[i]; k++)
						printf("row %d\n", i);
				}
			}
			for (j = 1; j <= M; j++)
			{
				if (MAX[j] > 0)
				{
					for (k = 1; k <= MAX[j]; k++)
						printf("col %d\n", j);
				}
			}
		}
		else
		{
			for (j = 1; j <= M; j++)
			{
				for (i = 1; i <= N; i++)
				{
					if (ar[i][j] < MAX[j])
						MAX[j] = ar[i][j];
				}
				for (i = 1; i <= N; i++)
				{
					sa[i][j] = MAX[j];
				}
			}
			for (i = 1; i <= N; i++)
			{
				for (j = 1; j <= M; j++)
				{
					if (ar[i][j] - sa[i][j] < MIN[i])
						MIN[i] = ar[i][j] - sa[i][j];
				}
				for (j = 1; j <= M; j++)
				{
					sa[i][j] += MIN[i];
					if (sa[i][j] != ar[i][j])
					{
						printf("-1\n");
						return 0;
					}
				}
			}
			int cnt = 0;
			for (i = 1; i <= N; i++)
			{
				if (MIN[i] > 0)
					cnt += MIN[i];
			}
			for (j = 1; j <= M; j++)
			{
				if (MAX[j] > 0)
					cnt += MAX[j];
			}
			printf("%d\n", cnt);
			for (i = 1; i <= N; i++)
			{
				if (MIN[i] > 0)
				{
					for (k = 1; k <= MIN[i]; k++)
						printf("row %d\n", i);
				}
			}
			for (j = 1; j <= M; j++)
			{
				if (MAX[j] > 0)
				{
					for (k = 1; k <= MAX[j]; k++)
						printf("col %d\n", j);
				}
			}
		}
	}
	return 0;
}
