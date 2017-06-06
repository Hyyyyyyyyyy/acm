#include <stdio.h>
int main()
{
	long long int i, j, k, u, n, m, a, b, ar[110][110];
	while (scanf("%lld %lld", &a, &b) != EOF)
	{
		for (i = 1; i <= 101; i++)
		{
			ar[i][0] = 1;
			ar[0][i] = 0;
		}
		ar[0][0] = 0;
		for (i =1; i <= a; i++)
		{
			for (j = 1; j <= b; j++)
			{
				ar[i][j] = ar[i - 1][j] * (j + 1) + ar[i - 1][j - 1] * (i - j);
				ar[i][j] %= 2007;
			}
		}
		printf("%lld\n", ar[a][b] % 2007);
	}
	return 0;
}
