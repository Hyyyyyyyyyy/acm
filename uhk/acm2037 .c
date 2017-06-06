#include <stdio.h>
#include <stdlib.h>
int comp(const void *r, const void *t);
struct jiemu
{
	int a;
	int b;
};
struct jiemu ar[999];
int main()
{
	int n, m, count;
	

	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
			break;
		for (m = 0; m < n; m++)
		{
			scanf("%d %d", &ar[m].a, &ar[m].b);
		}
		qsort(ar, n, sizeof(struct jiemu), comp);
		count = 1;
		for (m = 1; m < n; m++)
		{
			if (ar[m].a >= ar[m - 1].b)
				count++;
			else
				ar[m].b = ar[m - 1].b;
		}
		printf("%d\n", count);
	}
	return 0;
}

int comp(const void *r, const void *t)
{
	const struct jiemu * p1 = (const struct jiemu *)r;
	const struct jiemu * p2 = (const struct jiemu *)t;
	if (p1->b < p2->b)
		return -1;
	else if (p1->b == p2->b)
		return 0;
	else
		return 1;
}
