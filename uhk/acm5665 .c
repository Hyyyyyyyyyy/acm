#include <stdio.h>
int main()
{
	int n, m, i, u, doudou1, doudou2;
	int ar;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &m);
		doudou1 = 0;
		doudou2 = 0;
		for (u = 1; u <= m; u++)
		{
			scanf("%d", &ar);
			if (ar == 0)
				doudou1 = 1;
			if (ar == 1)
				doudou2 = 1;
		}
		if (doudou1 == 1 && doudou2 == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}