#include <stdio.h>
int main()
{
	char a, b, c;
	while	(scanf("%c%c%c", &a, &b, &c) == 3)
	{
		if (a > b)
		{
			if (a < c)
				printf("%c %c %c\n", b, a, c);
			else if (c > b)
				printf("%c %c %c\n", b, c, a);
			else
				printf("%c %c %c\n", c, b, a);
		}
		else
		{
			if (c > b)
				printf("%c %c %c\n", a, b, c);
			else if (c > a)
				printf("%c %c %c\n", a, c, b);
			else
				printf("%c %c %c\n", c, a, b);
		}
		getchar();
	}
	return 0;
}
