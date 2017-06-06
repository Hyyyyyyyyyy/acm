#include <stdio.h>
#include <string.h>
struct expense
{
	int wei, value;
};
int main()
{
	int n, m, i, j, k, u, bag[1000005], mwei, pigwei, c;
	struct expense pig[550];
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &pigwei, &mwei);

			mwei -= pigwei;

			scanf("%d", &c);
			for (u = 1; u <= c; u++)
			{
				scanf("%d %d", &pig[u].value, &pig[u].wei);
			}
			for (i = 1; i <= mwei; i++)
				bag[i] = 10000000;
			bag[0] = 0;
			for (i = 1; i <= c; i++)
			{
				for (j = pig[i].wei; j <= mwei; j++)
				{
					bag[j] = (bag[j] < bag[j - pig[i].wei] + pig[i].value) ? bag[j] : (bag[j - pig[i].wei] + pig[i].value);
				}
			}
			if (bag[mwei] == 10000000)
				printf("This is impossible.\n");
			else
				printf("The minimum amount of money in the piggy-bank is %d.\n", bag[mwei]);
		}
	}
	return 0;
}
