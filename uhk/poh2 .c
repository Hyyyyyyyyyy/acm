#include <stdio.h>
#include <string.h>
struct juz
{
	int ar[81][81];
};
struct juz multiply(struct juz a, struct juz b, int n, int m);
int main()
{
	int i, j, k, u, n, m, x, y, z;
	struct juz a, res, temp;
	while (scanf("%d %d %d", &x, &y, &z) != EOF)
	{
		for (i = 0; i < x; i++)
		{
			for (j = 0; j < x; j++)
			{
				scanf("%d", &a.ar[i][j]);
			}
		}
		memset(res.ar, 0, sizeof(res.ar));
		memset(temp.ar, 0, sizeof(temp.ar));

		for (i = x; i < 2 * x; i++)
		{
			res.ar[i-x][i] = 1;
		}
		for (i = 0; i < x; i++)
		{
			for (j = 0; j < x; j++)
			{
				temp.ar[i][j] = a.ar[i][j];
			}
		}
		for (i = x; i < x * 2; i++)
		{
			for (j = 0; j < x; j++)
			{
				temp.ar[i][j] = a.ar[i - x][j];
			}
		}
		for (i = x; i < 2 * x; i++)
		{
			temp.ar[i][i] = 1;
		}
		while (y > 0)
		{
			if (y % 2)
			{
				res = multiply(res, temp, x * 2, z);
			}
			temp = multiply(temp, temp, x * 2, z);
			y /= 2;
		}
		for (i = 0; i < x; i++)
		{
			for (j = 0; j < x; j++)
			{
				printf("%d ", res.ar[i][j]);
			}
			putchar('\n');
		}
	}
	return 0;
}

struct juz multiply(struct juz a, struct juz b, int n, int m)
{
	int i, j, k;
	struct juz temp;
	memset(temp.ar, 0, sizeof(temp.ar));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				temp.ar[i][j] += ((a.ar[i][k] % m) * (b.ar[k][j] % m)) % m;
				temp.ar[i][j] %= m;
			}
		}
	}
	return temp;
}
