#include <stdio.h>
#include <string.h>
int main()
{
	int n, m, i, j, k, pre[60], cur[60], num[30];
	long long int S;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			for (i = 1; i <= 26; i++)
				scanf("%d", &num[i]);
			memset(pre, 0, sizeof(int) * 60);
			memset(cur, 0, sizeof(int) * 60);
			for (i = 0; i <= num[1]; i++)
				pre[i] = 1;

			for (i = 2; i <= 26; i++)
			{
				if (num[i] == 0)
					continue;
				for (j = 0; j <= 50; j++)
				{
					for (k = 0; k <= num[i] * i && k + j <= 50; k = k + i)
					{
						cur[k + j] += pre[j];

					}
				}

				for (j = 0; j <= 50; j++)
				{
					pre[j] = cur[j];
					cur[j] = 0;
				}
			}

			S = 0;
			for (i = 1; i <= 50; i++)
				S += pre[i];

			printf("%lld\n", S);
			
		}
	}
	return 0;
}
