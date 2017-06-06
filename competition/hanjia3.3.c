#include <stdio.h>
int main()
{
	int i, j, k, n, m, x, y, doudou;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &x, &y);
			for (i = 0; i <= 100; i++)
			{
				if (x * (100 - y) + i * y >= 6000)
				{
					break;
				}
			
			}
			if (i <= 100)
				printf("%d\n", i);
			else
				printf("poor guy\n");
		}
	}
	return 0;
}
