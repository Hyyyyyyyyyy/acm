#include <stdio.h>
int main()
{
	int n, m, i, u;
	unsigned long long int ar[1000005], max, t;

	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%llu", &t);
			if (t == 1)
				printf("0\n");
			else if (t == 2)
				printf("1\n");
			else
			{
				ar[1] = 0;
				ar[2] = 1;
				for (i = 3; i <= t; i++)
				{
					if (i % 2 != 0)
					{
						ar[i] = ar[i - 1];
						max = ar[i];
						continue;
					}
					else
					{
						u = i - 2;
						max = ar[u] + ar[i - u];
						for (u = i - 4; u > i / 2; u = u - 2)
						{
							if (max < (ar[u] + ar[i - u]))
								max = ar[u] + ar[i - u];
						}
						if ((i / 2) % 2 == 0)
						{
							max = (max > (ar[i / 2] * 2 + 1)) ? max : (ar[i / 2] * 2 + 1);
						}
						ar[i] = max;
					}

				}
				printf("%llu\n", max);
			}
		}
	}
	getchar();
	return 0;
}
