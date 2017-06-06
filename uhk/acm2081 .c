#include <stdio.h>
int main()
{
	int n, m, i, u, L;
	char ar[9999];

	while (scanf("%d", &n) != EOF)
	{
		getchar();
		for (m = 1; m <= n; m++)
		{
			fgets(ar, 9999, stdin);
			ar[5] = '6';
			for (i = 5; i < 11; i++)
				printf("%c", ar[i]);
			putchar('\n');
		}
	}
	return 0;
}
