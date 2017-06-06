#include <stdio.h>
#include <stdlib.h>
int comp(const void *a, const void *b);
int main()
{
	int n, m, ar[9999], sa[9999], *p, *q, i, count, sf[9999];

	while (scanf("%d %d", &n, &m) != EOF)
	{
		if (n == 0 && m == 0)
			break;
		for (i = 0; i < n; i++)
			scanf("%d", &ar[i]);
		for (i = 0; i < m; i++)
			scanf("%d", &sa[i]);
		p = ar;
		q = sa;
		count = 0;

		while (p != &ar[n])
		{
			if (q == &sa[m])
			{
				sf[count] = *p;
				count++;
				p++;
				q = sa;
				continue;
			}
			if (*p != *q)
				q++;
			else
			{
				p++;
				q = sa;
			}
		}
		if (count)
		{
			qsort(sf, count, sizeof(int), comp);
			for (i = 0; i < count; i++)
				printf("%d ", sf[i]);
		}
		else
			printf("NULL");
		putchar('\n');
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
