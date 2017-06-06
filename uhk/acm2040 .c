#include <stdio.h>
int main()
{
	int n, m;
	double	a, b, c;

	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lf %lf %lf", &a, &b, &c);
			if (a > b)
			{
				a = a + b;
				b = a - b;
				a = a - b;
			}
			if (c < b)
			{
				b = c + b;
				c = b - c;
				b = b - c;
			}
			if (a > b)
			{
				a = a + b;
				b = a - b;
				a = a - b;
			}
			if ((a + b) > c && (c - b) < a)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}
