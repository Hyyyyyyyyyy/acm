#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 100000000;
const int MAXN = 250;
int ar[MAXN][MAXN];
int N, M;
int main()
{
	int i, j, k, u, n, m, a, b, c, sum, cas = 1;
	while (scanf("%d %d", &N, &M) != EOF && (N || M))
	{
		memset(ar, 0, sizeof(ar));
		sum = 0;
		for (m = 1; m <= M; m++)
		{
			scanf("%d %d", &a, &b);
			if (ar[b][a] || a == b)
			{
				sum++;
				continue;
			}
			if (ar[a][b])
				continue;
			ar[a][b] = 1;
			for (i = 1; i <= N; i++)
			{
				if (ar[i][a])
				{
					ar[i][b] = 1;
				}
				if (ar[b][i])
				{
					ar[a][i] = 1;
				}
			}
			for (i = 1; i <= N; i++)
			{
				if (ar[i][a])
				{
					for (j = 1; j <= N; j++)
					{
						if (ar[b][j])
						{
							ar[i][j] = 1;
						}
					}
				}
			}
		}
		printf("%d. %d\n", cas++, sum);
	}
	return 0;
}