#include <stdio.h>
int main()
{
	long long int i, j, k, u, n, m, count, S;
	while (scanf("%lld", &n) != EOF)
	{
		i = 0;
		j = 0;
		count = 0;
		m = n;
		while (m > 0)
		{
			count += m / 10;
			m /= 10;
		}
		m = n;
		while (m > 0)
		{
			i += m / 2;
			m /= 2;
		}
		m = n;
		while (m > 0)
		{
			j += m / 5;
			m /= 5;
		}
		if (i < j)
		{
			i -= count;
			count += i;
		}
		else
		{
			j -= count;
			count += j;
		}
		printf("%lld\n", count);
	}
	return 0;
}
