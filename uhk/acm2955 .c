#include <stdio.h>
#include <string.h>
struct bank
{
	int money;
	double c;
};
int main()
{
	int n, m, i, j, k, num, sum, u;
	double bag[11000], mcatch;
	struct bank Roy[110];
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			sum = 0;
			scanf("%lf %d", &mcatch, &num);

				for (u = 1; u <= num; u++)
				{
					scanf("%d %lf", &Roy[u].money, &Roy[u].c);
						sum += Roy[u].money;

				}
				bag[0] = 1;
				for (i = 0; i < 11000; i++)
					bag[i] = 0;
			for (i = 1; i <= num; i++)
			{
				for (j = sum; j >= Roy[i].money; j--)
				{
					bag[j] = (bag[j] > bag[j - Roy[i].money] * (1.0-Roy[i].c)) ? bag[j] : (bag[j - Roy[i].money] * (1.0-Roy[i].c));
				}
			}
			for (j = sum; j >= 0; j--)
			{
				if (bag[j] > (1.0-mcatch))
					break;
			}
			printf("%d\n", j);
		}
	}
	return 0;
}
