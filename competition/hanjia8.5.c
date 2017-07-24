#include <stdio.h>
int main()
{
	long long int n, p, q, a, b, c, doudou, i;
	while (scanf("%lld %lld %lld", &n, &p, &q) != EOF)
	{
		if (n <= p)
			printf("LOSE\n");
		doudou = 0;
		for (i = p; i <= q; i++)
		{
			if ((n - i) % (p + q) <= p)
			{
				printf("WIN\n");
				doudou = 1;
				break;
			}
		}
		if (doudou == 0)
			printf("LOSE\n");
	}
	return 0;
}
