#include <stdio.h>
int main()
{
	int x, y, temp;
	while (scanf("%d %d", &x, &y) != EOF && (x || y))
	{
		while (x != y)
		{
			if (x > y)
			{
				if (x % y != 0)
					x %= y;
				else
					x = y;
			}
			if (x < y)
			{
				if (y % x != 0)
					y %= x;
				else
					y = x;
			}
		}
		printf("%d\n", x);
	}
	return 0;
}
