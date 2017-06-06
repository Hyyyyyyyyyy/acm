#include <stdio.h>
int main()
{
	int n, m, i, j, k, sum, bag[120010], ar[7], cas = 1;
	while (scanf("%d %d %d %d %d %d", &ar[1], &ar[2], &ar[3], &ar[4], &ar[5], &ar[6]) != EOF && (ar[1] || ar[2] || ar[3] || ar[4] || ar[5] || ar[6]))
	{
		printf("Collection #%d:\n", cas++);
		sum = ar[1] * 1 + ar[2] * 2 + ar[3] * 3 + ar[4] * 4 + ar[5] * 5 + ar[6] * 6;
		if (sum % 2 != 0)
		{
			printf("Can't be divided.\n");
			putchar('\n');
			continue;
		}
		sum /= 2;
		for (i = 1; i <= sum; i++)
			bag[i] = -100000000;
		bag[0] = 0;
		for (i = 1; i <= 6; i++)
		{
			if (ar[i] == 0)
				continue;
			if (ar[i] * i >= sum)
			{
				for (j = i; j <= 120000; j++)
					bag[j] = (bag[j] > bag[j - i] + i) ? bag[j] : (bag[j - i] + i);
			}
			else
			{
				k = 1;
				while (k <= ar[i])
				{
					for (j = sum; j >= k*i; j--)
						bag[j] = (bag[j] > bag[j - k*i] + k*i) ? bag[j] : (bag[j - k*i] + k*i);
					ar[i] -= k;
					k *= 2;
				}
				if (ar[i])
					for (j = sum; j >= ar[i] * i; j--)
						bag[j] = (bag[j] > bag[j - ar[i] * i] + ar[i] * i) ? bag[j] : (bag[j - ar[i] * i] + ar[i] * i);
			}
		}
		if (bag[sum] > 0)
			printf("Can be divided.\n");
		else
			printf("Can't be divided.\n");
		
		putchar('\n');
	}

	return 0;
}
