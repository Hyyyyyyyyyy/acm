#include <stdio.h>
#include <string.h>
int main()
{
	int n, m, i, u, L, count;
	char ar[999];
	char max;
	while (fgets(ar, 999, stdin) != NULL)
	{
		max = 0;
		L = strlen(ar) - 1;
		max = ar[0];
		for (i = 0; i < L; i++)
		{
			if (max < ar[i])
				max = ar[i];
		}
		count = 0;
		for (i = 0; i < L+5*count; i++)
		{
			if (ar[i] == max)
			{
				count++;
				for (u = L-1+5*count; u > i; u--)
					ar[u + 5] = ar[u];
				ar[i + 1] = '(';
				ar[i + 2] = 'm';
				ar[i + 3] = 'a';
				ar[i + 4] = 'x';
				ar[i + 5] = ')';
				i = i + 5;
			}
		}
		for (u = 0; u < L + 5 * count; u++)
			printf("%c", ar[u]);
		putchar('\n');
	}
	return 0;
}