#include <stdio.h>
int main()
{
	int n, m, i, u, p, s, t, j;
	long long int ar[1000002], count[3];

	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &p);
			for (u = 1; u <= p; u++)
			{
				scanf("%lld", &ar[u]);
			}
			for (s = 1; s <= p; s++)
			{
				for (t = s + 1; t <= p; t++)
				{
					if (ar[t] == ar[s])
					{
						ar[t] = -1;
						ar[s] = -1;
					}
				}
			}
			j = 1;
			for (t = 1; t <= p; t++)
			{
				if (ar[t] != -1)
				{
					count[j] = ar[t];
					j++;
				}
				if (j == 3)
					break;
			}
			printf("%lld %lld\n", count[1], count[2]);
		}
	}
	return 0;
}