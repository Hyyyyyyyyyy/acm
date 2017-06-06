#include <stdio.h>
int main()
{
	int n, m, i, count, ar[1005], a, b;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
			break;
		scanf("%d", &m);
		for (i = 1; i <= n; i++)
			ar[i] = i;
		for (i = 1; i <= m; i++)
		{
			scanf("%d %d", &a, &b);
			if (a > b)
			{
				a = a + b;
				b = a - b;
				a = a - b;
			}
			while (ar[a] != a)
				a = ar[a];
			while (ar[b] != b)
				b = ar[b];
			if (ar[a] != ar[b])
				ar[b] = a;
			
		}
		count = 0;
		for (i = 1; i <= n; i++)
		{
			if (ar[i] == i)
				count++;
		}
		printf("%d\n", count - 1);
	}
	return 0;
}
