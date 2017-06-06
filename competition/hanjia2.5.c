#include <stdio.h>
#include <stdlib.h>
int comp(const void * p1, const void * p2);
int main()
{
	int i, j, k, u, n, m;
	long long ar[1005], count;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &k);
			for (u = 1; u <= k; u++)
			{
				scanf("%lld", &ar[u]);

			}
			qsort(&ar[1], k, sizeof(long long int), comp);
			count = 0;
			for (i = 1; i < k; i++)
				if (ar[i] != ar[i + 1])
					count++;
			printf("%lld\n", count+1);
		}
	}
}

int comp(const void * p1, const void * p2)
{
	return *(long long *)p1 - *(long long *)p2;
}

