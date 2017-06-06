#include <stdio.h>
#include <stdlib.h>

#include <math.h>
int comp(const void * p1, const void * p2);
int main()
{
	int i, j, k, n, m, u, x, y, ar[10010];
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &k);
			for (u = 0; u < k; u++)
			{
				scanf("%d", &ar[u]);
			}
			qsort(ar, k, sizeof(int), comp);
			j = 0;
			for (i = 0; i < k; i++)
			{
				if (i % 2 == 0)
					printf("%d ", ar[k - 1 - j]);
				else
				{
					printf("%d ", ar[j]);
					j++;
				}
			}
			putchar('\n');
		}
	}
	return 0;
}
int comp(const void * p1, const void * p2)
{
	return *(int *)p1 - *(int *)p2;
}