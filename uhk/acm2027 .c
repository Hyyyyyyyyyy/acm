#include <stdio.h>
#include <string.h>
int main()
{
	int m, n, i, u, L, count[5];
	char ar[105], *p, *q;
	char sf[] = { 'a', 'e', 'i', 'o', 'u' };
	int doudou;
	while (scanf("%d", &n) != EOF)
	{
		doudou = 0;
		getchar();
		while (n--)
		{
			if (doudou == 1)
				putchar('\n');
			doudou = 1;
			for (i = 0; i < 5; i++)
				count[i] = 0;
			fgets(ar, 105, stdin);
			L = strlen(ar) - 1;
			q = sf;
			for (u = 0; u < L; u++)
			{
				if (ar[u] == *q)
					count[0]++;
				else if (ar[u] == *(q + 1))
					count[1]++;
				else if (ar[u] == *(q + 2))
					count[2]++;
				else if (ar[u] == *(q + 3))
					count[3]++;
				else if (ar[u] == *(q + 4))
					count[4]++;
			}

			for (u = 0; u < 5; u++)
				printf("%c:%d\n", sf[u], count[u]);
		}
	}
	return 0;
}