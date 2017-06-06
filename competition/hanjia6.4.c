#include <stdio.h>
#include <math.h>
int main()
{
	int i, j, k, u, n, m, ar[1010], num[1010][2], max;
	while (scanf("%d", &n) != EOF && n)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &ar[m]);
			num[m][0] = 0;
			num[m][1] = 0;
		}
		num[1][1] = 1;
		for (i = 2; i <= n; i++)
		{
			for (j = 1; j <= i; j++)
			{
				if (ar[i] < ar[j] && num[i][0] < num[j][1] + 1)
					num[i][0] = num[j][1] + 1;
				if (ar[i] > ar[j] && num[i][1] < num[j][0] + 1)
						num[i][1] = num[j][0] + 1;
			}
		}
		max = 0;
		for (i = 1; i <= n; i++)
		{
			if (max < num[i][0])
				max = num[i][0];
			if (max < num[i][1])
				max = num[i][1];
		}
		printf("%d\n", max);
	}
	return 0;
}
