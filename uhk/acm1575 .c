#include <stdio.h>
#include <string.h>
struct juz
{
	unsigned long long int ar[11][11];
};

struct juz multiply(struct juz a, struct juz b, int n);
int main()
{
	int i, j, k, n, m, u, x, y;
	struct juz a, res;
	unsigned long long tr;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &x, &y);
			for (i = 0; i < x; i++)
			{
				for (j = 0; j < x; j++)
				{
					scanf("%llu", &a.ar[i][j]);
				}
			}
			memset(res.ar, 0, sizeof(unsigned long long int)*x*x);
			for (i = 0; i < x; i++)
				res.ar[i][i] = 1;
			while (y > 0)
			{
				if (y % 2)
				{
					res = multiply(res, a, x);
				}
				a = multiply(a, a, x);
				y /= 2;
			}
			tr = 0;
			for (i = 0; i < x; i++)
			{
				tr += res.ar[i][i] % 9973;
				tr %= 9973;
			}
			printf("%llu\n", tr);
		}
		
	}
	return 0;
}
struct juz multiply(struct juz a, struct juz b, int n)
{
	int i, j, k;
	struct juz temp;
	memset(temp.ar, 0, sizeof(unsigned long long int)*n*n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				temp.ar[i][j] + ((a.ar[i][k] % 9973) * (b.ar[k][j] % 9973)) % 9973;
				temp.ar[i][j] %= 9973;
			}
		}
	}
	return temp;
}