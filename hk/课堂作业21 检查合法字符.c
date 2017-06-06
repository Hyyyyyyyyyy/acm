#include <stdio.h>
#include <ctype.h>
int main()
{
	int i;
	char ar[999];

	fgets(ar, 999, stdin);
	if (isdigit(ar[0]))
		printf("Illegell\n");
	else
	{
		for (i = 1; ar[i] != '\n'; i++)
		{
			if (isdigit(ar[i]) || isalpha(ar[i]) || (ar[i] == '_'))
				continue;
			else
			{
				printf("Illegell\n");
				break;
			}
		}
		if (ar[i] == '\n')
			printf("Nice\n");
	}
	getchar();
	return 0;
}