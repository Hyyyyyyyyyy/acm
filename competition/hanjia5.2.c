#include <stdio.h>
int main()
{
	long long int i, j, n, m, k, u;
	while (scanf("%lld", &n) != EOF)
	{
		m = 1;
		k = 0;
		while (m*3 <= n)
		{
			m *= 3;
			k++;
		}
		if (m != n)
			k += 1;
		printf("%lld\n", k);
	}
	return 0;
}
