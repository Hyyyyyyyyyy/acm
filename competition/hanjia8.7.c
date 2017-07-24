#include <stdio.h>
int main()
{
	int i, j, k, n, m;
	while (scanf("%d", &n) != EOF)
	{
		m = 0;
		while (n > 0)
		{
			m += n / 5;
			n /= 5;
		}
		printf("%d\n", m);
	}
	return 0;
}