v#include <stdio.h>
int main()
{
	int n, m, a, b, i, u, ar[9999];

	while (scanf("%d", &n) != EOF)
	{
			i = 0;
			while (n)
			{
				ar[i] = n % 2;
				n /= 2;
				i++;
			}
			for (u = i - 1; u >= 0; u--)
				printf("%d", ar[u]);
			putchar('\n');
	}
	return 0;
}
