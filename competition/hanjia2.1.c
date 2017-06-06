
#include <stdio.h>
int main()
{
	int i, j, k, n, m, u, ar[100000];
	long long S;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &k);
			S = 0;
			for (u = 1; u <= k; u++)
			{
				scanf("%d", &ar[u]);
				if (ar[u] % 2 == 0)
					S += ar[u];
				else
					S -= ar[u];
			}
			printf("%lld\n", S);
		}
	}
	return 0;
}