#include <stdio.h>
#include <string.h>
int main()
{
	int n, m, a, b, u, i, j, k, pre[50], cur[50], num[50];
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &a, &b);
			for (u = 1; u <= b; u++)
			{
				scanf("%d %d", &u, &num[u]);
			}
			memset(pre, 0, sizeof(int) * 50);
			memset(cur, 0, sizeof(int) * 50);
			for (i = 0; i <= num[1]; i++)
				pre[i] = 1;
			for (i = 2; i <= b; i++)
			{
				for (j = 0; j <= a; j++)
				{
					for (k = 0; k <= num[i] * i && k + j <= a; k += i)
					{
						cur[k + j] += pre[j];
					}
				}
				for (j = 0; j <= a; j++)
				{
					pre[j] = cur[j];
					cur[j] = 0;
				}
			}

			printf("%d\n", pre[a]);
		}
	}
	return 0;
}