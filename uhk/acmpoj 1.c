#include <stdio.h>
#include <string.h>
struct juz
{
	int ar[2][2];
};
struct juz multiply(struct juz a, struct juz b, int n);
int main()
{
	int i, j, u, k, n, m;
	struct juz a, res;
	while (scanf("%d", &n) != EOF && n != -1)
	{
		m = n;
		a.ar[0][0] = 1;
		a.ar[0][1] = 1;
		a.ar[1][0] = 1;
		a.ar[1][1] = 0;
		res.ar[0][0] = 0;
		res.ar[0][1] = 1;
		while (m > 0)
		{
			if (m % 2)
			{
				res = multiply(res, a, 2);
			}
			a = multiply(a, a, 2);
			m /= 2;
		}
		printf("%d\n", res.ar[0][0]);
	}
	return 0;
}
struct juz multiply(struct juz a, struct juz b, int n)
{
	struct juz temp;
	int i, j, k;
	memset(temp.ar, 0, sizeof(int)*n*n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				temp.ar[i][j] += ((a.ar[i][k] % 10000) * (b.ar[k][j] % 10000)) % 10000;
				temp.ar[i][j] %= 10000;
			}
		}
	}
	return temp;
}
