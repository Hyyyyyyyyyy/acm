#include <stdio.h>
int main()
{
	int n, m, i, j, k, ar[1010];
	long long sum[1010], max;
	while (scanf("%d", &n) != EOF && n != 0)
	{
		for (i = 1; i <= n; i++)
			scanf("%d", &ar[i]);
		for (i = 1; i < 1010; i++)
			sum[i] = ar[i];
		max = 0;

		for (i = n; i >= 1; i--)
		{
			for (j = n; j > i; j--)
			{
				if (ar[i] < ar[j] && sum[i] < ar[i] + sum[j])
					sum[i] = ar[i] + sum[j];
			}
			if (max < sum[i])
				max = sum[i];
		}
		printf("%lld\n", max);
	}
	return 0;
}
