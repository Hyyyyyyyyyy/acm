#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int INF = 100000000;
const ll MOD = 1e9 + 7;
const int maxn = 50;
int visit[maxn][maxn];
int ar[maxn][maxn];
int N, M;
int dir[4][2] = { -1, 0, 0, -1, 1, 0, 0, 1 };
int main()
{
	int i, j, k, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &N, &M);
			int cnt = 0;
			for (i = 1; i <= N; i++)
			{
				for (j = 1; j <= M; j++)
				{
					scanf("%d", &ar[i][j]);
				}
			}
			int doudou = 0;
			for (i = 1; i <= N; i++)
			{
				if (i == 1 || i == N)
				{
					for (j = 1; j <= M; j++)
					{
						for (k = j + 1; k <= M; k++)
						{
							if (ar[i][j] == ar[i][k])
							{
								doudou = 1;
							}
						}
						if (doudou)
							break;
					}
					if (doudou)
						break;
				}
				else
				{
					for (j = 1; j < M; j++)
					{
						if (ar[i][j] == ar[i][j + 1])
							doudou = 1;
					}
					if (doudou)
						break;
				}
			}
			if (!doudou)
			{
				for (j = 1; j <= M; j++)
				{
					if (j == 1 || j == M)
					{
						for (i = 1; i <= N; i++)
						{
							for (k = i + 1; k <= N; k++)
							{
								if (ar[i][j] == ar[k][j])
									doudou = 1;
							}
							if (doudou)
								break;
						}
						if (doudou)
							break;
					}
					else
					{
						for (i = 1; i < N; i++)
						{
							if (ar[i][j] == ar[i + 1][j])
								doudou = 1;
						}
						if (doudou)
							break;
					}
				}
			}
			if (doudou)
				printf("Case #%d: Yes\n", m);
			else
				printf("Case #%d: No\n", m);
		}
	}
	return 0;
}