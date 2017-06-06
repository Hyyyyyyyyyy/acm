#include <stdio.h>

int main()
{
	int i, j, k, u, n, m, x, y, set[100];
	long long num[100], max;
	while (scanf("%d %d", &n, &m) != EOF && (n != 0 || m != 0))
	{
		for (i = 1; i <= n; i++)
		{
			num[i] = 0;
		}
		max = 0;
		for (u = 1; u <= m; u++)
		{
			scanf("%d %d", &x, &y);
			num[x]++;
			if (max < num[x])
				max = num[x];
			num[y]++;
			if (max < num[y])
				max = num[y];
			
		}
		printf("%lld\n", max);
	}
	return 0;
}