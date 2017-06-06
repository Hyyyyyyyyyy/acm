#include <cstdio>
#include <cstring>
#include <cstdlib>
struct node
{
	int val;
	int m;
};
int main()
{
	struct node ar[150];
	int bag[150], i, j, k, u, n, a, b, cnt, count, tempp, tempm;
	while (scanf("%d", &a) != EOF && a)
	{
		scanf("%d", &b);
		for (i = 1; i <= b; i++)
		{
			scanf("%d %d", &ar[i].val, &ar[i].m);
		}
		memset(bag, 0, sizeof(bag));
		for (i = 1; i <= b; i++)
		{
			for (j = a; j >= 0; j--)
			{
				for (k = 1; k <= ar[i].m; k++)
				{
					tempm = k;
					tempp = k * ar[i].val;
					if (j < tempm)
						continue;
					bag[j] = (bag[j] > bag[j - tempm] + tempp) ? bag[j] : (bag[j - tempm] + tempp);
				}
			}
		}
		printf("%d\n", bag[a]);
	}
	return 0;
}
