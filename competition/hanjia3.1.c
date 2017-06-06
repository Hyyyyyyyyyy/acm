#include <stdio.h>
int main()
{
	int i, j, n, m;
	char ar[1005];
	while (fgets(ar, 1005, stdin) != NULL)
	{
		n = 0;
		for (i = 0; ar[i] != '\0'; i++)
		{
			if (ar[i] == 'a')
			{
				n++;
			}
		}
		if (n % 3 == 0)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}