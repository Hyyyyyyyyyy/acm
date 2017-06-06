#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void paixu(double sf[]);
int comp(const void *, const void *);
int main()
{
	int i;
	double * sf;
	double ar[10];
	for (i = 0; i < 10; i++)
		scanf("%lf", &ar[i]);
	sf = ar;
	paixu(sf);
	for (i = 0; i < 10; i++)
		printf("%.2lf ", ar[i]);
	putchar('\n');
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();

	return 0;
}

void paixu(double * sf)
{
	int i;
	for (i = 0; i < 10; i++)
		sf[i] = fabs(sf[i]);
	qsort(sf, 10, sizeof(double), comp);
}

int comp(const void * a, const void * b)
{
	const double * p1 = (const double *)a;
	const double * p2 = (const double *)b;
	if (*p1 < *p2)
		return -1;
	else if (*p1 == *p2)
		return 0;
	else
		return 1;
}

//564.153 546.156 561.615 456.561 879.123 8479.56 849.516 4589.516 8496 456