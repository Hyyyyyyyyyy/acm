#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char ar[50], sa[50], ag[50], sg[50], sf[100], st[100], temp;
	char t[10][10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	int i, j, k, u, n, m, L, L1, L2;
	long long a, b, c, count, d;
	while (scanf("%s", ar) != EOF && scanf("%s", sa) != EOF)
	{
		L1 = strlen(ar);
		L2 = strlen(sa);
		a = 0;
		b = 0;
		count = 1;
		for (i = L1 - 1; i >= 0; i--)
		{
			strcpy(ag, &ar[i]);
			for (j = 0; j <= 9; j++)
			{
				if (strcmp(ag, t[j]) == 0)
				{
					a = a + j * count;
					ar[i] = '\0';
					count *= 10;
				}
			}
		}
		count = 1;
		for (i = L2 - 1; i >= 0; i--)
		{
			strcpy(sg, &sa[i]);
			for (j = 0; j <= 9; j++)
			{
				if (strcmp(sg, t[j]) == 0)
				{
					b = b + j * count;
					sa[i] = '\0';
					count *= 10;
				}
			}
		}
		c = 0;
		d = a + b;
		itoa(d, st, 10);
		L = strlen(st);
		for (i = 0; i <= (L - 1) / 2; i++)
		{
			temp = st[i];
			st[i] = st[L - 1 - i];
			st[L - 1 - i] = temp;
		}
		j = L - 1;
		sf[0] = '\0';
		while (j >= 0)
		{
			strcat(sf, t[st[j] - '0']);
			j--;
		}
		L = strlen(sf);
		puts(sf);

	}
	return 0;
}
