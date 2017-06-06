#include <stdio.h>
#include <string.h>
int main()
{
	int n, m, i, u, doudou, L;
	char ar[9999], *p, *q;

	while (scanf("%d", &n) != EOF)
	{
		getchar();
		for (m = 1; m <= n; m++)
		{
			doudou = 1;
			fgets(ar, 9999, stdin);
			L = strlen(ar) - 1;
			p = ar;
			q = &ar[L - 1];
			for (i = 1; i <= L / 2; i++)
			{
				if (*q != *p)
				{
					doudou = 0;
					break;
				}
				else
				{
					p++;
					q--;
				}
			}
			if (doudou == 1)
				printf("yes\n");
			else
				printf("no\n");
		}
	}
	return 0;
}
