#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int comp(const void *a, const void *b);
int main()
{
	int n, m, i, j, u, fried[505], standrad;
	long long int S;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &m);
			for (u = 1; u <= m; u++)
				scanf("%d", &fried[u - 1]);
			qsort(fried, m, sizeof(int), comp);
			S = 0;
			standrad = m / 2;
			for (j = 0; j < m; j++)
				S += abs(fried[j] - fried[standrad]);
			printf("%lld\n", S);
		}
	}
	return 0;
}

int comp(const void *a, const void *b)
{
	const int * p1 = (const int *)a;
	const int * p2 = (const int *)b;
	if (*p1 < *p2)
		return -1;
	else if (*p1 == *p2)
		return 0;
	else
		return 1;
}
