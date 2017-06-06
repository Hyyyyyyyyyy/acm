#include <stdio.h>
int main()
{
	int n, m, i, j, k, u, ar[105][105], c, d, doudou;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &c, &d);

			for (i = 1; i <= c; i++)
			{
				for (j = 1; j <= c; j++)
				{
					scanf("%d", &ar[i][j]);

				}
			}
			doudou = 0;
			if ((d / 90) % 4 == 0)
			{

				for (i = 1; i <= c; i++)
				{
					doudou = 0;
					for (j = 1; j <= c; j++)
					{
						if (doudou)
							putchar(' ');
						doudou = 1;
						printf("%d", ar[i][j]);

						if (j == c)
							putchar('\n');
					}
				}
			}
			else if ((d / 90) % 4 == 1)
			{

				for (i = 1; i <= c; i++)
				{
					doudou = 0;
					for (j = 1; j <= c; j++)
					{
						if (doudou)
							putchar(' ');
						doudou = 1;
						printf("%d", ar[c+1-j][i]);
						if (j == c)
							putchar('\n');
					}
				}

			}
			else if ((d / 90) % 4 == 2)
			{
				for (i = 1; i <= c; i++)
				{
					doudou = 0;
					for (j = 1; j <= c; j++)
					{
						if (doudou)
							putchar(' ');
						doudou = 1;
						printf("%d", ar[c + 1 - i][c + 1 - j]);

						if (j == c)
							putchar('\n');
					}
				}
			}
			else if ((d / 90) % 4 == 3)
			{
				for (i = 1; i <= c; i++)
				{
					doudou = 0;
					for (j = 1; j <= c; j++)
					{
						if (doudou)
							putchar(' ');
						doudou = 1;
						printf("%d", ar[j][c+1-i]);

						if (j == c)
							putchar('\n');
					}
				}
			}
			putchar('\n');
		}
	}
	return 0;
}

