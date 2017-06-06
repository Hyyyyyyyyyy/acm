#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int i, j, k, u, n, m, L, p, q;
	char ar[27], x, y;
	while (scanf("%d", &n) != EOF)
	{
		getchar();
		scanf("%s", ar);
		getchar();
		scanf("%d", &k);
		getchar();
		for (u = 1; u <= k; u++)
		{
			scanf("%c", &x);
			getchar();
			scanf("%c", &y);
			getchar();
			for (i = 0; i < n; i++)
			{
				if (ar[i] == x)
					p = i;
				if (ar[i] == y)
					q = i;
			}
			if (p > q)
				printf("After\n");
			else
				printf("Before\n");
		}
		
	}
	return 0;
}