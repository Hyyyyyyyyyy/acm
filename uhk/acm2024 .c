#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
	int n, m, i, L, doudou;
	char ar[60];

	while (scanf("%d", &n) != EOF)
	{
		//getchar();
		for (m = 1; m <= n; m++)
		{
		
			doudou = 0;
			gets(ar);
			L = strlen(ar);
			if (isalpha(ar[0]) || ar[0] == '_')
			{
				for (i = 1; i < L; i++)
				{
					if (isalpha(ar[i]) || (ar[i] == '_') || isdigit(ar[i]))
						doudou = 1;
					else
					{
						doudou = 0;
						break;
					}
				}
				if (doudou == 1)
					printf("yes\n");
				else
					printf("no\n");
			}
			else
				printf("no\n");
		}
	}
	return 0;
}
