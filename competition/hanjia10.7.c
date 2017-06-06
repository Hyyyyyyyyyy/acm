#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int a, b, c, i, j, k, n, m, ar[110], count;
	while (scanf("%d", &n) != EOF && n)
	{

		for (m = 1; m <= n; m++)
		{
			scanf("%d", &ar[m]);
		}
		for (i = 1; i <= n; i++)
		{
			count = 1;
			if (ar[i] == -1)
				continue;
			for (j = i + 1; j <= n; j++)
			{
				if (ar[i] == ar[j] && ar[j] != -1)
				{
					count++;
					ar[j] = -1;
				}
			}
			if (count % 2 != 0)
			{
				printf("%d\n", ar[i]);
				break;
			}
		}
	}
	return 0;
}
