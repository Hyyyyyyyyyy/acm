#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main()
{
	int i, j, k, u, n, m, x, y, q, doudou = 0, dodo = 0;
	double ar[1000010];
	long long num;
	double ave, max, min;
	char sa[10];
	while (scanf("%d", &n) != EOF)
	{
		doudou = 0;
		for (m = 1; m <= n; m++)
		{
			scanf("%lf", &ar[m]);
		}
		num = n;
		scanf("%d", &q);
		
		for (u = 1; u <= q; u++)
		{
			scanf("%s", sa);
			if (strcmp(sa, "Query") == 0)
			{
				ave = 0.0;
				max = 0.0;
				min = 10000000.0;
				for (i = 1; i <= num; i++)
				{
					ave += ar[i];
					max = (max < ar[i]) ? ar[i] : max;
					min = (min > ar[i]) ? ar[i] : min;
				}
				if (doudou == 0 && dodo == 1)
				{
					putchar('\n');

					doudou = 1;
				}

				printf("%.2lf\n", (ave-max-min)/(num-2));
			}
			else
			{
				scanf("%d", &k);
				for (j = 1; j <= k; j++)
				{
					scanf("%lf", &ar[num + j]);
				}
				num += k;
			}
		}
		dodo = 1;
	}
	return 0;
}
