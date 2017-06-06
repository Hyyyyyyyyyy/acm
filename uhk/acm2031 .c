#include <stdio.h>
int main()
{
	int n, m, u, i;
	int ar[999];
	while (scanf("%d %d", &n, &m) != EOF)
	{
		i = 0;
		if (n >= 0) 
		{
			while (n > 0)
			{
				ar[i] = n % m;
				n = n / m;
				i++;
			}
		}
		else
		{
			n = n*(-1);
			while (n > 0)
			{
				ar[i] = n % m;
				n = n / m;
				i++;
			}
			printf("-");
		}
		for (u = i - 1; u >= 0; u--)
		{
			if ((ar[u] + 48) >= 48 && (ar[u] + 48) <= 57)
				printf("%c", ar[u] + 48);
			else
				printf("%c", ar[u] - 10 + 65);
		}
		putchar('\n');
	}
	return 0;
}
