#include <stdio.h>
int main()
{
	int i, j, k, u, n, m;
	unsigned long long a, b, c, S, t;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%llu %llu %llu", &a, &b, &c);
			if (a < b)
			{
				t = a;
				a = b;
				b = t;
			}
			S = 0;
			a = a%c;
			b = b %c;
			while (a > 0)
			{
				if (a % 2 != 0)
				{
					S += b%c;
				}
				a /= 2;
				b *= 2;
				b %= c;
			}
			printf("%llu\n", S%c);
		}
	}
	return 0;
}

