#include <stdio.h>
#include <string.h>
int main()
{
	int n, m, i, j, k, u, count, doudou, L1, L2;
	char ar[10010], sa[20], *p1, *p2, *q;
	while (scanf("%d", &n) != EOF)
	{
		getchar();
		for (m = 1; m <= n; m++)
		{
			count = 0;
			scanf("%s", ar);
			scanf("%s", sa);
			L1 = strlen(ar);
			L2 = strlen(sa);
		
			doudou = 0;
			count = 0;
			for (p1 = ar; *p1 != '\0'; p1++)
			{
				p2 = p1;
				q = sa;
				if (*p1 == *q)
				{
					for (p2 = p1,q = sa; *q != '\0'; q++, p2++)
					{
						if (*q != *p2 && *q != '\0')
						{
							doudou = 0;
							break;
						}
						else
							doudou = 1;
					}
					if (doudou == 1)
					{
						count++;
						doudou = 0;
					}
				}
				
			}
			printf("%d\n", count);
		}
	}
	return 0;
}
