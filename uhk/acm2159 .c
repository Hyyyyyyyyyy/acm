#include <stdio.h>
#include <string.h>
struct monster
{
	int exp;
	int pati;
};
int main()
{
	int n, m, i, j, k, u, bag[105][105], mexp, mpati, mkind, mkill, doudou;
	struct monster xhd[105];
	while (scanf("%d %d %d %d", &mexp, &mpati, &mkind, &mkill) != EOF)
	{
		for (m = 1; m <= mkind; m++)
		{
			scanf("%d %d", &xhd[m].exp, &xhd[m].pati);
		}
		for (i = 0; i < 105; i++)
		{
			for (j = 0; j < 105; j++)
				bag[i][j] = -1000000;
		}
		bag[0][0] = 0;
		for (i = 1; i <= mkind; i++)
		{
			for (j = xhd[i].pati; j <= mpati; j++)
			{
				for (k = 1; k <= mkill; k++)
				{
					bag[j][k] = (bag[j][k] > bag[j - xhd[i].pati][k - 1] + xhd[i].exp) ? bag[j][k] : (bag[j - xhd[i].pati][k - 1] + xhd[i].exp);
				}
			}
		}
		doudou = 0;
		for (j = 0; j <= mpati; j++)
		{
			for (k = 0; k <= mkill; k++)
			{
				if (bag[j][k] >= mexp)
				{
					printf("%d\n", mpati - j);
					doudou = 1;
					break;
				}
			}
			if (doudou)
				break;
		}
		if (doudou == 0)
		{
			printf("-1\n");
		}
	}
	return 0;
}
