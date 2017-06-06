#include <stdio.h>
int main()
{
	int n, i, u, ar[35][35], doudou, p;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
		{
			ar[i][0] = 1;
			ar[i][i] = 1;
		}
		for (u = 2; u < n; u++)
		{
			for (i = 1; i < u; i++)
			{
				ar[u][i] = ar[u - 1][i - 1] + ar[u - 1][i];
			}
		}
		for (u = 0; u < n; u++)
		{
			doudou = 0;
			for (p = 1; p <= n - u; p++)
			{
				putchar(' ');
			}
			for (i = 0; i <= u; i++)
			{
				if (doudou == 1)
					putchar(' ');
				doudou = 1;
				printf("%d", ar[u][i]);
			}
			putchar('\n');
		}
		putchar('\n');
	}
	return 0;
}
