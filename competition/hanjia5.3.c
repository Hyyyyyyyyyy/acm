#include <stdio.h>
#include <string.h>
int main()
{
	int i, j, k, u, n, m, b, e, set[100010], max, temp;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &k);
			memset(set, 0, sizeof(set));
			for (u = 0; u < k; u++)
			{
				scanf("%d %d", &b, &e);
				set[b]++;
				set[e]--;
			}

			max = 0;
			temp = 0;
			for (i = 0; i < 100009; i++)
			{
				temp += set[i];
				if (max < temp)
					max = temp;
			}
			printf("%d\n", max);
		}
	}
	return 0;
}