#include <stdio.h>
#include <string.h>
struct juz
{
	int ar[5][5];
};
struct juz multiply(struct juz a, struct juz b, int n, int m);
int main()
{
	int i, j, k, u, n, m, t;
	struct juz a, res;
	while (scanf("%d %d", &n, &u) != EOF)
	{
		memset(res.ar, 0, sizeof(res.ar));
		memset(a.ar, 0, sizeof(a.ar));
		a.ar[0][0] = 1;
		a.ar[0][1] = 1;
		a.ar[1][2] = 1;
		a.ar[2][0] = 1;
		a.ar[2][3] = 1;
		a.ar[3][0] = 1;
		res.ar[0][0] = 6;
		res.ar[0][1] = 4;
		res.ar[0][2] = 2;
		res.ar[0][3] = 1;
		if (n == 0)
		{
			printf("%d\n", 1 % u );
			continue;
		}
		else if (n == 1)
		{
			printf("%d\n", 2%u);
			continue;
		}
		else if (n == 2)
		{
			printf("%d\n", 3%u);
			continue;
		}
		else if (n == 3)
		{
			printf("%d\n", 6%u);
			continue;
		}
		t = n - 3;
		while (t > 0)
		{
			if (t % 2)
			{
				res = multiply(res, a, 4, u);
			}
			a = multiply(a, a, 4, u);
			t /= 2;
		}
		printf("%d\n", res.ar[0][0]);
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
				temp.ar[i][j] += ((a.ar[i][k] % m)*(b.ar[k][j] % m)) % m;
				temp.ar[i][j] %= m;
			}
		}
	}
	return temp;
}
