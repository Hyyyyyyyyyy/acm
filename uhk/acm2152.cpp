#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 110;
int pre[maxn], cur[maxn], limit[maxn][2];
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		memset(pre, 0, sizeof(pre));
		memset(cur, 0, sizeof(cur));
		int sum = 0;
		for (i = 1; i <= n; i++)
		{
			scanf("%d %d", &limit[i][0], &limit[i][1]);
		}
		for (i = limit[1][0]; i <= limit[1][1]; i++)
			pre[i] = 1;
		for (i = 2; i <= n; i++)
		{
			for (j = 0; j <= m; j++)
			{
				for (k = limit[i][0]; k <= limit[i][1] && k + j <= m; k++)
				{
					cur[k + j] += pre[j];
				}
			}
			for (j = 0; j <= m; j++)
			{
				pre[j] = cur[j];
				cur[j] = 0;
			}
		}
		printf("%d\n", pre[m]);
	}
	return 0;
}