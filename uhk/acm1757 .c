#include <stdio.h>
#include <string.h>
struct juz
{
	long long ar[10][10];
};
struct juz multiply(struct juz a, struct juz b, int n, int m);

int main()
{
	int i, j, k, u, n, m, t;
	struct juz a, res;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		memset(a.ar, 0, sizeof(a.ar));
		memset(res.ar, 0, sizeof(res.ar));
		for (i = 0; i < 10; i++)
		{
			scanf("%lld", &a.ar[i][0]);
		}
		for (i = 1; i < 10; i++)
			a.ar[i - 1][i] = 1;
		for (i = 0; i < 10; i++)
			res.ar[0][i] = 9 - i;
		if (n < 10)
		{
			printf("%lld\n", res.ar[0][n] % m);
			continue;
		}
		else
		{
			t = n - 9;
			while (t > 0)
			{
				if (t % 2)
				{
					res = multiply(res, a, 10, m);
				}
				a = multiply(a, a, 10, m);
				t /= 2;
			}
			printf("%lld\n", res.ar[0][0]);
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