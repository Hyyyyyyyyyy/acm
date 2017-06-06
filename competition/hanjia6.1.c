#include <stdio.h>
int main()
{
	int i, j, k, n, m, u, a, b, x, y, max, sum;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			max = -1;
			scanf("%d %d", &a, &b);
			for (i = a; i <= b; i++)
			{
				sum = 0;
				for (j = 1; j <= i; j++)
				{
					if (i % j == 0)
						sum += j;
				}
				sum -= 2 * i;
				if (max < sum && sum > 0)
					max = sum;
			}
			if (max != -1)
				printf("%d\n", max);
			else
				printf("-1\n");
		}
	}
	return 0;
}