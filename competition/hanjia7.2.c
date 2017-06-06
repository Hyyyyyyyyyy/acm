#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int i, j, k, u, n, m, L, l, L1, L2, cas = 0, count, doudou = 0;
	char ar[200000];

	while (fgets(ar, 200000, stdin) != NULL)
	{
		char sa[2000];
		count = 0;
		cas++;
		L = strlen(ar);
		j = 1;
		for (i = 0; i < L - 1; i++)
		{
			if (ar[i] != '-' && ar[i] != '+')
			{
				count++;
				if (j < 1)
					j = 1;
				if (j > count)
					j = count;

				for (u = count - 1; u >= j; u--)
				{
					sa[u + 1] = sa[u];
				}
				sa[j] = ar[i];
				j++;
			}
			if (ar[i] == '-')
			{
				j--;
			}
			if (ar[i] == '+')
			{
				j++;
			}
		}
		sa[count + 1] = '\0';
		if (doudou)
		{
			putchar('\n');
		}
		doudou = 1;
		printf("Case %d:", cas);
		puts(&sa[1]);
	}
	return 0;
}
