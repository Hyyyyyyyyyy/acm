#include <stdio.h>
int main()
{
	int i, j, k, n, m;
	while (scanf("%d %d", &n, &m) != EOF && (n || m))
	{

		if ((m*n) % 8 == 0 && n >= 2 && m >= 2)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
